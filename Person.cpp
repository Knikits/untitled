#include "Person.h"
#include <QDebug>
using namespace std;

bool is_number(std::string line)
{
    const std::string numbers = "0123456789";
    for (int x = 0; x < (int)(line.size()); x++)
    {
        for (int y = 0; y < (int)(numbers.size()); y++)
        {
            if (numbers[y] == line[x])
                return true;
        }
    }
    return false;
}

// конструктор ФИО
Person::Person(const std::string & last_name, const std::string & first_name, const std::string & patronymic)
{
    if (is_number(last_name))
    {
        this->last_name = "-ERROR-";
        if (is_number(first_name))
        {
            this->first_name = "-ERROR-";
        }
        else this->first_name = first_name;
        if (is_number(patronymic))
        {
            this->patronymic = "-ERROR-";
        }
        else this->patronymic = patronymic;
    }
    if (!is_number(last_name))
    {
        this->last_name = last_name;
        if (is_number(first_name))
        {
            this->first_name = "-ERROR-";
        }
        else this->first_name = first_name;
        if (is_number(patronymic))
        {
            this->patronymic = "-ERROR-";
        }
        else this->patronymic = patronymic;
    }
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
std::shared_ptr<char[]> Person::String()
{
    int length = last_name.length() + first_name.length() + patronymic.length() + 3; //+3 для пробелов и знака о том, что строка окончена.
    std::shared_ptr<char[]> FIO (new char[length]); // Выделение памяти под динамический массив
    int i = 0;
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
