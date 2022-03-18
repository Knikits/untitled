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
