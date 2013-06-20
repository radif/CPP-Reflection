//
//  main.cpp
//  cppReflection
//
//  Created by Radif Sharafullin on 6/20/13.
//  Copyright (c) 2013 MCB. All rights reserved.
//

#include <iostream>
#include "Derived1.h"
#include "Derived2.h"

int main(int argc, const char * argv[])
{

    
    
    //templated instantiation, no casting required
    {
        std::cout <<"templated instantiation, no casting required"<<std::endl<<std::endl;
        auto base(mcb::PlatformSupport::Base::create<mcb::PlatformSupport::Base *>("Base"));
        auto derived1(mcb::PlatformSupport::Base::create<mcb::PlatformSupport::Derived1 *>("Derived1"));
        auto derived2(mcb::PlatformSupport::Base::create<mcb::PlatformSupport::Derived2 *>("Derived2"));

            
        std::cout << base->stringFromClass() << std::endl;
        std::cout << derived1->stringFromClass() << std::endl;
        std::cout << derived2->stringFromClass() << std::endl;
    }
    
    //instantiation of the pinters casted to the base class
    
    //templated instantiation, no casting required
    {
        
        std::cout <<"templated instantiation, no casting required"<<std::endl<<std::endl;
        
        auto base(mcb::PlatformSupport::Base::create("Base"));
        auto derived1(mcb::PlatformSupport::Base::create("Derived1"));
        auto derived2(mcb::PlatformSupport::Base::create("Derived2"));
        
        
        std::cout << base->stringFromClass() << std::endl;
        std::cout << derived1->stringFromClass() << std::endl;
        std::cout << derived2->stringFromClass() << std::endl;
    }
    
    return 0;
}

