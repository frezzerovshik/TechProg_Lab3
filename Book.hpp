//
//  Book.hpp
//  T.P.L.B.3
//
//  Created by Артем Шарапов on 21/04/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#pragma once
#include "Base.hpp"

class Book: public Base
{
public:
    Book();
    Book(fstream &ptr);
    Book(const char a[],const char b[],const char c[],const char d[],const char e[]);
    Book(const Book& init);
    ~Book();
    string* getName(){return &name;}
    string* getYear(){return &year;}
    string* getPublisher(){return &publisher;}
    string* getNum(){return &num;}
    string* getAnnotacion(){return &annotacion;}
    void setData();
    void print();
    void say_my_name();
};
