//
//  Base.h
//  cppReflection
//
//  Created by Radif Sharafullin on 6/20/13.
//  Copyright (c) 2013 MCB. All rights reserved.
//

#ifndef __cppReflection__Base__
#define __cppReflection__Base__

#include <iostream>
#include "BaseReflection.h"

namespace mcb{namespace PlatformSupport{
    class Base {
    public:
        REGISTER_CLASS_FOR_REFLECTION_H(Base);
        template <typename T>
        static T create(const std::string & className){return dynamic_cast<T>(Base::create(className));}
        static Base * create(const std::string & className);

        Base();
        virtual ~Base();
    };
}}

#endif /* defined(__cppReflection__Base__) */
