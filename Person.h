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
    Person& operator=(Person const& person); //присвоение
    Person(const Person&); //копирование
    const std::string& getLastName() const { return last_name; }
    const std::string& getFirstName() const { return first_name; }
    const std::string& getPatronymic() const { return patronymic; }
    void setLastName(const std::string&);
    void setFirstName(const std::string&);
    void getPatronymic(const std::string&);
    char* String();
};

#endif // PERSON_H
