#ifndef PERSON_H
#define PERSON_H
#include <iostream>

class Person
{
private:
    std::string last_name;
    std::string first_name;
    std::string patronymic;
public:
    Person(const std::string & last_name = "", const std::string & first_name = "", const std::string & patronymic = "");
    Person(const Person&); //копирование
    Person& operator=(Person const& person); //присвоение
    const std::string& getLastName() const { return last_name; }
    const std::string& getFirstName() const { return first_name; }
    const std::string& getPatronymic() const { return patronymic; }
    void setLastName(const std::string& last_name) {this->last_name = last_name;}
    void setFirstName(const std::string& first_name) {this->first_name = first_name;}
    void setPatronymic(const std::string& patronymic){this->patronymic = patronymic;}
    char* String();
};

#endif // PERSON_H
