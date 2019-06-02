//
//  Base.hpp
//  T.P.L.B.3
//
//  Created by Артем Шарапов on 21/04/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#pragma once
#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;
class Base
{
protected:
    string name;
    string year;
    string publisher;
    string num;
    string annotacion;
public:
    virtual ~Base(){cout<<"Base dead"<<endl;};
    virtual void print() = 0;
    virtual void say_my_name()=0;
};
