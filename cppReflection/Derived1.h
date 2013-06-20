//
//  Derived1.h
//  cppReflection
//
//  Created by Radif Sharafullin on 6/20/13.
//  Copyright (c) 2013 MCB. All rights reserved.
//

#ifndef __cppReflection__Derived1__
#define __cppReflection__Derived1__

#include "Base.h"
namespace mcb{namespace PlatformSupport{
    class Derived1 : public Base{
    public:
        REGISTER_CLASS_FOR_REFLECTION_H(Derived1);
    };
}}


#endif /* defined(__cppReflection__Derived1__) */
