//
//  BaseReflection.h
//  mcb
//
//  Created by Radif Sharafullin on 6/9/13.
//
//

#ifndef __mcb__BaseReflection_h
#define __mcb__BaseReflection_h

#include <string>
#include <map>

namespace mcb{namespace PlatformSupport{

    
#define REGISTER_CLASS_FOR_REFLECTION_H(className) \
static mcb::PlatformSupport::DerivedClassRegister<className> reg;\
virtual std::string stringFromClass(){return #className;}
    
#define REGISTER_CLASS_FOR_REFLECTION_CPP(className) \
mcb::PlatformSupport::DerivedClassRegister<className> className::reg(#className)
    
    class Base;
    typedef std::map<std::string, Base*(*)()> reflection_map_type;
    static reflection_map_type * _mcbBaseReflectionMap(nullptr);
    
    class ReflectionFactory {
        friend class Base;
        static Base * createInstance(const std::string & s) {
            auto it(_reflectionMap()->find(s));
            if(it!=_reflectionMap()->end())
                return it->second();
            return nullptr;
        }
        
        template<typename T>
        static Base * instantiateClass() {
            T * retVal(new T());
            if (retVal){
                //possible multistep initialization
                return retVal;
            }
            delete retVal;
            retVal = nullptr;
            return nullptr;
        }
       
    protected:
        static reflection_map_type * _reflectionMap() {

            static std::once_flag onceFlag;
            std::call_once(onceFlag,[](){
                if(!_mcbBaseReflectionMap)
                    _mcbBaseReflectionMap = new reflection_map_type;
            });
            
            return _mcbBaseReflectionMap;
        }
        
    };
    
    template<typename T>
    class DerivedClassRegister : public ReflectionFactory {
    public:
        DerivedClassRegister(const std::string & s){
            _reflectionMap()->insert({s, &instantiateClass<T>});
#if defined (DEBUG) && DEBUG==1
            printf(" ---> reflection: registering class:-> %s\n",s.c_str());
#endif
        }
    };

}}

#endif/*(#ifndef __mcb__BaseReflection_h)*/
