#include "Person.h"

// конструктор ФИО
Person::Person(const std::string & last_name, const std::string & first_name, const std::string & patronymic)
{
    this->last_name = last_name;
    this->first_name = first_name;
    this->patronymic = patronymic;
}

// оператор присвоения
Person& Person::operator=(const Person &person)
{
    this->last_name = person.last_name;
    this->first_name = person.first_name; // экземпляры класса Person
    this->patronymic = person.patronymic;
    return *this;
}

// копирование
Person::Person(const Person &person)
{
    this->last_name = person.last_name;
    this->first_name = person.first_name; // экземпляры класса Person
    this->patronymic = person.patronymic;
}

//Нужно возвратить char* в виде строки
char* Person::String()
{
    int length = last_name.length() + first_name.length() + patronymic.length() + 3; //+3 для пробелов и знака о том, что строка окончена.
    char* FIO = new char[length];
    int i = 0;
    if (last_name.length() == 0)
        last_name = '-';
    if (first_name.length() == 0) // если где-то вводдим без имени, то ставится прочерки при чтении из файла
        first_name = '-';
    if (patronymic.length() == 0)
        patronymic = '-';
    for(i = 0; i < last_name.length(); i++)
    {
        FIO[i] = last_name[i]; // записывается фамилия
    }
    FIO[i] = ' '; // ставится пробел
    i++; // переход к имени
    // переменная i нужна для всего ФИО, а j понадобится для отдельно взятого слова (фамилия, имя, отчество)
    int j = 0;
    for(; j < first_name.length(); i++, j++)
    {
        FIO[i] = first_name[j]; // записывается имя
    }
    FIO[i] = ' '; // ставится пробел
    i++; // переход к отчеству
    for(j = 0; j < patronymic.length(); i++, j++)
    {
        FIO[i] = patronymic[j]; // записывается отчество
    }
    FIO[i] = '\0'; // конец для строки ФИО
    return FIO; // возвращаем char
}
