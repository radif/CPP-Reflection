//
//  Base.cpp
//  cppReflection
//
//  Created by Radif Sharafullin on 6/20/13.
//  Copyright (c) 2013 MCB. All rights reserved.
//

#include "Base.h"
namespace mcb{namespace PlatformSupport{
    REGISTER_CLASS_FOR_REFLECTION_CPP(Base);
    
    Base * Base::create(const std::string & className){
        Base * retVal(ReflectionFactory::createInstance(className));
        //possible multistep initialization goes here
        return retVal;
    }
    
    Base::Base(){}
    Base::~Base(){}
}}