#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <memory>

// Класс персоны
class Person
{
private:
    std::string last_name; // фамилия
    std::string first_name; // имя
    std::string patronymic; // отчество
public:
    Person(const std::string & last_name = "", const std::string & first_name = "", const std::string & patronymic = "");
    Person& operator=(Person const& person); //присвоение
    Person(const Person&); //копирование
    const std::string& getLastName() const { return last_name; }
    const std::string& getFirstName() const { return first_name; } // геттеры
    const std::string& getPatronymic() const { return patronymic; }
    std::shared_ptr<char[]> String(); // для преобразования поля для сообщения QDebug
    void setLastName(const std::string& last_name) {this->last_name = last_name;}
    void setFirstName(const std::string& first_name) {this->first_name = first_name;} // сеттеры
    void setPatronymic(const std::string& patronymic){this->patronymic = patronymic;}
};

#endif // PERSON_H
