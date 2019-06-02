//
//  Journal.hpp
//  T.P.L.B.3
//
//  Created by Артем Шарапов on 21/04/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#ifndef Journal_hpp
#define Journal_hpp

#include <stdio.h>

#endif /* Journal_hpp */
#include "Base.hpp"
class Journal : public Base
{
public:
    ~Journal();
    Journal();
    Journal(fstream &ptr);
    Journal(const char a[],const char b[],const char c[],const char d[],const char e[]);
    Journal(const Journal& init);
    string* getName(){return &name;}
    string* getYear(){return &year;}
    string* getPublisher(){return &publisher;}
    string* getNum(){return &num;}
    string* getAnnotacion(){return &annotacion;}
    void setData();
    void print();
    void say_my_name();
};
