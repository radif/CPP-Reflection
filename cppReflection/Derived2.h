//
//  Derived2.h
//  cppReflection
//
//  Created by Radif Sharafullin on 6/20/13.
//  Copyright (c) 2013 MCB. All rights reserved.
//

#ifndef __cppReflection__Derived2__
#define __cppReflection__Derived2__

#include "Derived1.h"

namespace mcb{namespace PlatformSupport{
    class Derived2 : public Derived1{
    public:
        REGISTER_CLASS_FOR_REFLECTION_H(Derived2);
    };
}}
#endif /* defined(__cppReflection__Derived2__) */
