//
//  Book.cpp
//  T.P.L.B.3
//
//  Created by Артем Шарапов on 21/04/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Book.hpp"
Book::Book(fstream &ptr)
{
    
    getline(ptr , name);
    
    getline(ptr , year);
    
    getline(ptr , publisher);
    
    getline(ptr, num);
    
    getline(ptr , annotacion);
}
Book::Book()
{
    name=year=publisher=num=annotacion='0';
}
Book::~Book()
{
    cout<<"Book dead"<<endl;
}

Book::Book(const char a[],const char b[],const char c[],const char d[],const char e[])
{
    name=a;
    year=b;
    publisher=c;
    num=d;
    annotacion=e;
}
Book::Book(const Book& init)
{
    name = init.name;
    year=init.year;
    publisher=init.publisher;
    num=init.num;
    annotacion=init.annotacion;
}
void Book::say_my_name()
{
    cout<<"Книга"<<endl;
}

void Book::setData()
{
    cout<<"Введите наименование"<<endl;
    getline(cin , name);
    cout<<"Введите год издания"<<endl;
    getline(cin , year);
    cout<<"Введите издателя"<<endl;
    getline(cin , publisher);
    cout<<"Введите количество страниц"<<endl;
    getline(cin, num);
    cout<<"Напишите аннотацию"<<endl;
    getline(cin , annotacion);
}
void Book::print()
{
    this->say_my_name();
    cout<<"Наименование: "<<name<<endl;
    cout<<"Год издания: "<<year<<endl;
    cout<<"Издатель:"<<publisher<<endl;
    cout<<"Количество страниц:"<<num<<endl;
    cout<<"Аннотация:\n"<<annotacion<<endl;
}
