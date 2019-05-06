//
//  Journal.cpp
//  T.P.L.B.3
//
//  Created by Артем Шарапов on 21/04/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Journal.hpp"
Journal::Journal(fstream &ptr)
{
    getline(ptr , name);
    getline(ptr , year);
    getline(ptr , publisher);
    getline(ptr, num);
    getline(ptr , annotacion);
}
Journal::Journal()
{
    name=year=publisher=num=annotacion='0';
}
Journal::~Journal()
{
    cout<<"journal dead"<<endl;
}
void Journal::say_my_name()
{
    cout<<"Журнал"<<endl;
}
Journal::Journal(const char a[],const char b[],const char c[],const char d[],const char e[])
{
    name=a;
    year=b;
    publisher=c;
    num=d;
    annotacion=e;
}
Journal::Journal(const Journal& init)
{
    name = init.name;
    year=init.year;
    publisher=init.publisher;
    num=init.num;
    annotacion=init.annotacion;
}
void Journal::print()
{
    this->say_my_name();
    cout<<"Наименование: "<<name<<endl;
    cout<<"Год издания: "<<year<<endl;
    cout<<"Издатель:"<<publisher<<endl;
    cout<<"Количество страниц:"<<num<<endl;
    cout<<"Аннотация:\n"<<annotacion<<endl;
}
void Journal::setData()
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
