CPP-Reflection
==============

Reflection is not supported by current c++ standard, This examples demonstrates how to adopt reflection in your c++ code, particularly, string fromClass and classFromString. It relies on templates and a couple of short macros. The Factory functions are indexed in a map against the class string. The map is static, therefore is instantiated before int main() is given a chance to run. Making the reflection available right at the start without any setup code being required to run.

Here is an example on how to use the reflection:

	//templated instantiation, no casting required
	{
	    std::cout <<std::endl<<"templated instantiation, no casting required"<<std::endl<<std::endl;
	    auto base(mcb::PlatformSupport::Base::create<mcb::PlatformSupport::Base *>("Base"));
	    auto derived1(mcb::PlatformSupport::Base::create<mcb::PlatformSupport::Derived1 *>("Derived1"));
	    auto derived2(mcb::PlatformSupport::Base::create<mcb::PlatformSupport::Derived2 *>("Derived2"));
    
    
	    std::cout << base->stringFromClass() << std::endl;
	    std::cout << derived1->stringFromClass() << std::endl;
	    std::cout << derived2->stringFromClass() << std::endl;
	}


	//instantiation of the pointers casted to the base class, heavily relying on virtual functions
	{
	    std::cout <<std::endl<<"instantiation of the pointers casted to the base class, heavily relying on virtual functions"<<std::endl<<std::endl;
    
	    auto base(mcb::PlatformSupport::Base::create("Base"));
	    auto derived1(mcb::PlatformSupport::Base::create("Derived1"));
	    auto derived2(mcb::PlatformSupport::Base::create("Derived2"));
    
    
	    std::cout << base->stringFromClass() << std::endl;
	    std::cout << derived1->stringFromClass() << std::endl;
	    std::cout << derived2->stringFromClass() << std::endl;
	}

To add your class into the reflection map, you must inherit from Base, however with little code modification this requirement can go away. I personally prefer having a base class to rely on certain behavior even if I don't have the class information/declaration included.

in .h file:

	#include "Base.h"
	namespace mcb{namespace PlatformSupport{
	    class Derived1 : public Base{
	    public:
	        REGISTER_CLASS_FOR_REFLECTION_H(Derived1);
	    };
	}}

in .cpp file:

	#include "Derived1.h"
	namespace mcb{namespace PlatformSupport{
	    REGISTER_CLASS_FOR_REFLECTION_CPP(Derived1);
	}}