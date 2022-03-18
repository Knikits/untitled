#include "Person.h"

Person::Person(const std::string & last_name, const std::string & first_name, const std::string & patronymic)
{
    this->last_name = last_name;
    this->first_name = first_name;
    this->patronymic = patronymic;
}

Person& Person::operator=(const Person &person)
{
    this->last_name = last_name;
    this->first_name = first_name;
    this->patronymic = patronymic;
    return *this;
}

Person::Person(Person const& person)
{
    this->last_name = last_name;
    this->first_name = first_name;
    this->patronymic = patronymic;
}

//Нужно возвратить char* в виде строки
char* Person::String()
{
    int length = last_name.length() + first_name.length() + patronymic.length() + 3; //+3 для пробелов и перехода на новую строку
    char* name = new char[length];
    long long unsigned i = 0;
    for(i = 0; i < last_name.length(); i++)
        name[i] = last_name[i];
    name[i] = ' ';
    i++;
    // i общая для записи, но не для подсчитывания символов в каждом слове ...
}
