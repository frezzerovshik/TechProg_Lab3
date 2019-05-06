//
//  main.cpp
//  T.P.L.B.3
//
//  Created by Артем Шарапов on 20/04/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <Curses.h>
#include "Base.hpp"
#include "Journal.hpp"
#include "Textbook.hpp"
#include "Book.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    char mode;
    bool ask = true;
    bool exit = true;
    vector<Journal> mas_j;
    vector<Textbook> mas_t;
    vector<Book> mas_b;
    //Base *ptr;
    Journal *tmp_j;
    Textbook *tmp_t;
    Book *tmp_b;
    fstream reading;
    ofstream writing;
    while(ask)
    {
    system("clear");
    cout<<"Для начала выберите, с каким видом печатного издания вы хотите работать: "<<endl;
    cout<<"1 - журнал"<<endl<<"2 - учебник"<<endl<<"3 - книга"<<endl;
    cin >> mode;
    switch (mode) {
        case '1':
        
            reading.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/journal.txt");
            if (!reading.is_open())
            {cout<<"Ошибка открытия файла journal.txt"<<endl;break;}
            
         while(!reading.eof())
            {
                tmp_j = new Journal(reading);
                mas_j.push_back(*tmp_j);
                delete tmp_j;
                tmp_j = nullptr;
            }
            reading.close();
            break;
        
        case '2':
        
            reading.open("textbook.txt");
            if (!reading.is_open())
            {cout<<"Ошибка открытия файла textbook.txt"<<endl;break;}
            
            while(!reading.eof())
            {
                tmp_t = new Textbook(reading);
                mas_t.push_back(*tmp_t);
                delete tmp_t;
                tmp_t = nullptr;
            }
            reading.close();
            break;
        
        case '3':
        
            reading.open("book.txt");
            if (!reading.is_open())
            {cout<<"Ошибка открытия файла book.txt"<<endl;break;}
            
            while(!reading.eof())
            {
                tmp_b = new Book(reading);
                mas_b.push_back(*tmp_b);
                delete tmp_b;
                tmp_b = nullptr;
            }
            break;
        
        default:
            break;
    }
        cout<<"Хотите заполнить оставшиеся списки? 1 - да, 2 - нет"<<endl;
        getchar();
        if(getchar() == '2')
            ask = false;
    }
    do
    {
        cout<<"Выберите действие, которое хотите совершить:"<<endl<<"1. Найти запись"<<endl<<"2. Вывести на экран все данные о печатном издании"<<endl<<"3.Добавить запись"<<endl<<"4.Удалить запись"<<endl<<"5.Выход из программы"<<endl;;
        cin>>mode;
        switch (mode) {
            case '1':
            {
                char tmp_mode;
                cout<<"В каком списке искать?"<<endl;
                cin>>tmp_mode;
                switch (tmp_mode) {
                    case '1':
                    {
                        system("clear");
                        if(mas_j.empty())
                        {
                            cout<<"Список пуст"<<endl;
                            break;
                        }
                        cout<<" Поиск записи по наименованию"<<endl;
                        string search;
                        cout<<"Введите наименование искомого издания"<<endl;
                        getchar();
                        getline(cin,search);
                        for(int i = 0;i<mas_j.size();++i)
                        {
                            if(search == *(mas_j[i].getName()) )
                            {
                                cout<<"Нужное произведение есть в списке!"<<endl;
                                mas_j[i].print();
                                getchar();
                            }
                            else
                            {
                                    continue;
                            }
                        }
                        break;
                }
                    case '2':
                    {
                        system("clear");
                        if(mas_t.empty())
                        {
                            cout<<"Список пуст"<<endl;
                            break;
                        }
                        cout<<" Поиск записи по наименованию"<<endl;
                        string search;
                        cout<<"Введите наименование искомого издания"<<endl;
                        getline(cin,search);
                        for(int i = 0;i<mas_t.size();++i)
                        {
                            if(search == *(mas_t[i].getName()) )
                            {
                                cout<<"Нужное произведение есть в списке!"<<endl;
                                mas_t[i].print();
                                getchar();
                            }
                            else
                            {
                                    continue;
                            }
                        }
                        break;
                    }
                    case '3':
                    {
                        system("clear");
                        if(mas_b.empty())
                        {
                            cout<<"Список пуст"<<endl;
                            break;
                        }
                        cout<<" Поиск записи по наименованию"<<endl;
                        string search;
                        cout<<"Введите наименование искомого издания"<<endl;
                        getline(cin,search);
                        for(int i = 0;i<mas_b.size();++i)
                        {
                            if(search == *(mas_b[i].getName()) )
                            {
                                cout<<"Нужное произведение есть в списке!"<<endl;
                                mas_b[i].print();
                                getchar();
                            }
                            else
                            {
                                    continue;
                            }
                        }
                        break;
                }
                    default:
                        break;
                }
                break;
            }
            case '2':
            {
                system("clear");
                cout<<"Какой список хотите вывести на экран?"<<endl;
                char tmp_mode;
                cin>>tmp_mode;
                switch (tmp_mode) {
                    case '1':
                    {
                        system("clear");
                        if(mas_j.empty())
                        {
                            cout<<"Список пуст"<<endl;
                            break;
                        }
                        for(int i = 0;i<mas_j.size();++i)
                            mas_j[i].print();
                        break;
                    }
                    case '2':
                    {
                        system("clear");
                        if(mas_t.empty())
                        {
                            cout<<"Список пуст"<<endl;
                            break;
                        }
                        for(int i = 0;i<mas_t.size();++i)
                            mas_t[i].print();
                      
                        break;
                    }
                    case '3':
                    {
                        system("clear");
                        if(mas_b.empty())
                        {
                            cout<<"Список пуст"<<endl;
                            break;
                        }
                        for(int i = 0;i<mas_b.size();++i)
                            mas_b[i].print();
                      
                        break;
                    }
                    default:
                        break;
                }
            }
                break;
            case '3':
            {
                system("clear");
                char tmp_mode;
                cout<<"В какой список хотите добавить элемент?"<<endl;
                cin>>tmp_mode;
                switch (tmp_mode) {
                    case '1':
                    {
                        system("clear");
                        tmp_j = new Journal;
                        cout<<"Введите данные"<<endl;
                        getchar();
                        cout<<"Если ничего не происходит, нажмите Enter"<<endl;
                        tmp_j->setData();
                        mas_j.push_back(*tmp_j);
                        delete tmp_j;
                        tmp_j = nullptr;
                        break;
                    }
                    case '2':{
                        system("clear");
                        tmp_t = new Textbook;
                        cout<<"Введите данные"<<endl;
                        getchar();
                        cout<<"Если ничего не происходит, нажмите Enter"<<endl;
                        tmp_t->setData();
                        mas_t.push_back(*tmp_t);
                        delete tmp_t;
                        tmp_t = nullptr;
                        break;
                    }
                    case '3':
                    {
                        system("clear");
                        tmp_b = new Book;
                        cout<<"Введите данные"<<endl;
                        getchar();
                        cout<<"Если ничего не происходит, нажмите Enter"<<endl;
                        tmp_b->setData();
                        mas_b.push_back(*tmp_b);
                        delete tmp_b;
                        tmp_b = nullptr;
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case '4':
            {
                system("clear");
                char tmp_mode;
                cout<<"Из какого списка хотите удалить элемент?"<<endl;
                cin>>tmp_mode;
                getchar();
                switch (tmp_mode) {
                    case '1':
                    {
                        system("clear");
                        string search;
                        cout<<"Введите наименование  издания, которое хотите удалить"<<endl;
                        getline(cin,search);
                        for(int i = 0;i<mas_j.size();++i)
                        {
                            if(search == *(mas_j[i].getName()) )
                            {
                                mas_j.erase(mas_j.begin()+i);
                            }
                            else
                            {
                                if (i == mas_j.size()-1)
                                {
                                    cout<<"Такой записи в списке нет:("<<endl;
                                }
                                else
                                    continue;
                            }
                        }
                        break;
                    }
                    case '2':{
                        system("clear");
                        string search;
                        cout<<"Введите наименование  издания, которое хотите удалить"<<endl;
                        getline(cin,search);
                        for(int i = 0;i<mas_t.size();++i)
                        {
                            if(search == *(mas_t[i].getName()) )
                            {
                                mas_t.erase(mas_t.begin()+i);
                            }
                            else
                            {
                                if (i == mas_t.size()-1)
                                {
                                    cout<<"Такой записи в списке нет:("<<endl;
                                }
                                else
                                    continue;
                            }
                        }
                        break;
                    }
                    case '3':
                    {
                        system("clear");
                        string search;
                        cout<<"Введите наименование  издания, которое хотите удалить"<<endl;
                        getline(cin,search);
                        for(int i = 0;i<mas_b.size();++i)
                        {
                            if(search == *(mas_b[i].getName()) )
                            {
                                mas_b.erase(mas_b.begin()+i);
                            }
                            else
                            {
                                if (i == mas_b.size()-1)
                                {
                                    cout<<"Такой записи в списке нет:("<<endl;
                                }
                                else
                                    continue;
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case'5':
            {
                if(!mas_j.empty())
                {
                    writing.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/journal.txt");
                    if(!writing.is_open())
                    {
                        cout<<"Ошибка открытия файла journal.txt , запись данных невозможна"<<endl;
                        break;
                    }
                    for(int i = 0;i<mas_j.size();++i)
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
                if(!mas_t.empty())
                {
                    writing.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/textbook.txt");
                    if(!writing.is_open())
                    {
                        cout<<"Ошибка открытия файла textbook.txt , запись данных невозможна"<<endl;
                        break;
                    }
                    for(int i = 0;i<mas_t.size();++i)
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
                if(!mas_b.empty())
                {
                    writing.open("/Users/frez2zerovshik/Documents/T.P.L.B.3/T.P.L.B.3/book.txt");
                    if(!writing.is_open())
                    {
                        cout<<"Ошибка открытия файла book.txt , запись данных невозможна"<<endl;
                        break;
                    }
                    for(int i = 0;i<mas_b.size();++i)
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
            default:
                break;
        }
    }while(exit);
    system("clear");
    cout<<"До новых встреч!"<<endl<<"Все исходные файлы обновлены"<<endl;
    return 0;
}
