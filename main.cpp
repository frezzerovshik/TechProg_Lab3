//
//  main.cpp
//  T.P.L.B.3
//
//  Created by Артем Шарапов on 20/04/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include <iostream>
#include <new>
#include <fstream>
#include <Curses.h>
#include "Base.hpp"
#include "Journal.hpp"
#include "Textbook.hpp"
#include "Book.hpp"
#include <limits>
using namespace std;

int main(int argc, const char * argv[]) {
    char mode;
    bool ask = true;
    bool exit = true;
    Journal *mas_j = nullptr;
    Textbook *mas_t = nullptr;
    Book *mas_b = nullptr;
    Journal *tmp_j = nullptr;
    Textbook *tmp_t = nullptr;
    Book *tmp_b = nullptr;
    int num_j = 0;
    int num_t = 0;
    int num_b = 0;
    fstream reading;
    ofstream writing;
    while(ask)
    {
    system("clear");
    cout<<"Для начала выберите, с каким видом печатного издания вы хотите работать: "<<endl;
    cout<<"1 - журнал"<<endl<<"2 - учебник"<<endl<<"3 - книга"<<endl;
        cin>>mode;
    switch (mode) {
        case '1':
        
            reading.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/journal.txt");
            if (!reading.is_open())
            {cout<<"Ошибка открытия файла journal.txt"<<endl;break;}
            reading>>num_j;
            reading.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mas_j = new Journal[num_j];
            for (int i = 0; i < num_j; ++i)
            {
                Journal a(reading);
                mas_j[i] = a;
            }
            reading.close();
            break;
        
        case '2':
        
            reading.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/textbook.txt");
            if (!reading.is_open())
            {cout<<"Ошибка открытия файла textbook.txt"<<endl;break;}
           
            reading>>num_t;
             reading.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mas_t = new Textbook[num_t];
            for (int i = 0; i < num_t; ++i)
            {
                Textbook a(reading);
                mas_t[i] = a;//здесь память для объекта не выделяется, но инициализируется
            }
            reading.close();
            break;
        
        case '3':
        
            reading.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/book.txt");
            if (!reading.is_open())
            {cout<<"Ошибка открытия файла book.txt"<<endl;break;}
           
            reading>>num_b;
            reading.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mas_b = new Book[num_b];
            for (int i = 0; i < num_t; ++i)
            {
                Book a(reading);
                mas_b[i] = a;//здесь память для объекта не выделяется, но инициализируется
            }
            reading.close();
            break;
        
        default:
            break;
    }
        cout<<"Хотите заполнить оставшиеся списки? 1 - да, 2 - нет"<<endl;
        char a;
        cin>>a;
        if(a == '2')
            ask = false;
    }
    do
    {
        cout<<"Выберите действие, которое хотите совершить:"<<endl<<"1. Вывести на экран все данные о печатном издании"<<endl<<"2.Добавить запись"<<endl<<"3.Удалить запись"<<endl<<"4.Выход из программы"<<endl;;
        cin>>mode;
        switch (mode) {
            case'1':
            {
                char ask;
                cout<<"Выберите список:"<<endl<<"1 - Journal"<<endl<<"2 - Textbook"<<endl<<"3 - Book"<<endl;
                cin>>ask;
                switch(ask)
                {
                    case '1':
                    {
                        for(int i = 0;i<num_j;++i)
                        {
                            mas_j[i].print();
                            cout<<endl;
                        }
                        break;
                    }
                    case '2':
                    {
                        for(int i = 0;i<num_t;++i)
                        {
                            mas_t[i].print();
                            cout<<endl;
                        }
                        break;
                    }
                    case '3':
                    {
                        for(int i = 0;i<num_b;++i)
                        {
                            mas_b[i].print();
                            cout<<endl;
                        }
                        break;
                    }
                }
                break;
            }
            case '2':
            {
                char ask;
                cout<<"Выберите список:"<<endl<<"1 - Journal"<<endl<<"2 - Textbook"<<endl<<"3 - Book"<<endl;
                cin>>ask;
                switch(ask)
                {
                    case'1':
                    {
                        
                        tmp_j = new Journal[num_j];
                        for(int i =0;i<num_j;++i)
                            tmp_j[i] = mas_j[i];
                        //delete[] mas_j;
                      
                        mas_j = new Journal[++num_j];
                        for(int i =0;i<num_j;++i)
                        {
                            if(i == num_j-1)
                            {
                                mas_j[i].setData();
                            }
                            else
                                mas_j[i] = tmp_j[i];
                        }
                          //delete[] tmp_j;
                        break;
                    }
                    case '2':
                    {
                        
                        tmp_t = new Textbook[num_t];
                        for(int i =0;i<num_t;++i)
                            tmp_t[i] = mas_t[i];
                       // delete[] mas_t;
                        
                        mas_t = new Textbook[++num_t];
                        for(int i =0;i<num_t;++i)
                        {
                            if(i == num_t-1)
                            {
                                mas_t[i].setData();
                            }
                            else
                                mas_t[i] = tmp_t[i];
                        }
                       // delete[] tmp_t;
                        break;
                    }
                    case'3':
                    {
                        tmp_b = new Book[num_b];
                        for(int i =0;i<num_b;++i)
                            tmp_b[i] = mas_b[i];
                       // delete[] mas_b;
                        
                        mas_b = new Book[++num_b];
                        for(int i =0;i<num_b;++i)
                        {
                            if(i == num_b-1)
                            {
                                mas_b[i].setData();
                            }
                            else
                                mas_b[i] = tmp_b[i];
                        }
                       // delete[] tmp_b;
                        break;
                    }
                }
                break;
            }
            case'3':
            {
                char ask;
                cout<<"Выберите список:"<<endl<<"1 - Journal"<<endl<<"2 - Textbook"<<endl<<"3 - Book"<<endl;
                cin>>ask;
                switch(ask)
                {
                    case'1':
                    {
                        tmp_j = new Journal[--num_j];
                        for(int i =0;i<num_j;++i)
                            tmp_j[i] = mas_j[i];
                    
                        mas_j = new Journal[num_j];
                        for(int i =0;i<num_j;++i)
                                mas_j[i] = tmp_j[i];
                       // delete[] tmp_j;
                        break;
                    }
                    case'2':
                    {
                        tmp_b = new Book[--num_b];
                        for(int i =0;i<num_b;++i)
                            tmp_b[i] = mas_b[i];
                      
                        mas_b = new Book[num_b];
                        for(int i =0;i<num_b;++i)
                            mas_b[i] = tmp_b[i];
                        //delete[] tmp_b;
                        break;
                    }
                    case'3':
                    {
                        tmp_t = new Textbook[--num_t];
                        for(int i =0;i<num_t;++i)
                            tmp_t[i] = mas_t[i];
                        
                        mas_t = new Textbook[num_t];
                        for(int i =0;i<num_t;++i)
                            mas_t[i] = tmp_t[i];
                       // delete[] tmp_t;
                        break;
                    }
                }
                break;
            }
            case '4':
            {
                if(num_j!=0)
                {
                    writing.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/journal.txt");
                    if(!writing.is_open())
                    {
                        cout<<"Ошибка открытия файла journal.txt , запись данных невозможна"<<endl;
                        break;
                    }
                    writing<<num_j<<endl;
                    for(int i = 0;i<num_j;++i)
                    {
                        string *tmp =mas_j[i].getName();
                        writing<< *tmp<<endl;
                        tmp =mas_j[i].getYear();
                        writing<<*tmp<<endl;
                        tmp =mas_j[i].getPublisher();
                        writing<<*tmp<<endl;;
                        tmp =mas_j[i].getNum();
                        writing<<*tmp<<endl;
                        tmp =mas_j[i].getAnnotacion();
                        writing<<*tmp<<endl;
                    }
                    writing.close();
                }
                if(num_t!=0)
                {
                    writing.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/textbook.txt");
                    if(!writing.is_open())
                    {
                        cout<<"Ошибка открытия файла textbook.txt , запись данных невозможна"<<endl;
                        break;
                    }
                    writing<<num_t;
                    for(int i = 0;i<num_t;++i)
                    {
                        string *tmp =mas_t[i].getName();
                        writing<< *tmp<<endl;
                        tmp =mas_t[i].getYear();
                        writing<<*tmp<<endl;
                        tmp =mas_t[i].getPublisher();
                        writing<<*tmp<<endl;;
                        tmp =mas_t[i].getNum();
                        writing<<*tmp<<endl;
                        tmp =mas_t[i].getAnnotacion();
                        writing<<*tmp<<endl;
                    }
                    writing.close();
                }
                if(num_b!=0)
                {
                    writing.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/book.txt");
                    if(!writing.is_open())
                    {
                        cout<<"Ошибка открытия файла book.txt , запись данных невозможна"<<endl;
                        break;
                    }
                    writing<<num_b;
                    for(int i = 0;i<num_b;++i)
                    {
                        string *tmp =mas_b[i].getName();
                        writing<< *tmp<<endl;
                        tmp =mas_b[i].getYear();
                        writing<<*tmp<<endl;
                        tmp =mas_b[i].getPublisher();
                        writing<<*tmp<<endl;;
                        tmp =mas_b[i].getNum();
                        writing<<*tmp<<endl;
                        tmp =mas_b[i].getAnnotacion();
                        writing<<*tmp<<endl;
                    }
                    writing.close();
                }
                exit = false;
                break;
            }
        }
    }while(exit);
    if(mas_j!=nullptr)
    delete[]mas_j;
    if(mas_t!=nullptr)
    delete[]mas_t;
    if(mas_b!=nullptr)
    delete[]mas_b;
    system("clear");
    cout<<"До новых встреч!"<<endl<<"Все исходные файлы обновлены"<<endl;
    return 0;
}
