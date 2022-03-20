#include "Person.h"

Person::Person(const std::string & last_name, const std::string & first_name, const std::string & patronymic)
{
    this->last_name = last_name;

    this->first_name = first_name;

    this->patronymic = patronymic;
}

Person& Person::operator=(const Person &person)
{
    this->last_name = person.last_name;

    this->first_name = person.first_name;

    this->patronymic = person.patronymic;

    return *this;
}

Person::Person(Person const& person)
{
    this->last_name = person.last_name;

    this->first_name = person.first_name;

    this->patronymic = person.patronymic;
}

//Нужно возвратить char* в виде строки
char* Person::String()
{
    int length = last_name.length() + first_name.length() + patronymic.length() + 3; //+3 для пробелов и знака о том, что строка окончена.
    char* FIO = new char[length];
    long long unsigned i = 0;
    for(i = 0; i < last_name.length(); i++)
    {
        FIO[i] = last_name[i];
    }
    FIO[i] = ' ';
    i++;
    // переменная i нужна для каждого из слов ФИО, а j понадобится для отдельно взятого слова
    int j = 0;
    for(; j < first_name.length(); i++, j++)
    {
        FIO[i] = first_name[j];
    }
    FIO[i] = ' ';
    i++;
    for(j = 0; j < patronymic.length(); i++, j++)
    {
        FIO[i] = patronymic[j];
    }
    FIO[i] = '\0'; // конец для строки ФИО
    return FIO;
}
