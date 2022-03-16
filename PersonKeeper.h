#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include "Stack.h"
#include "Person.h"
#include <fstream>

class PersonKeeper
{
private:
    PersonKeeper(){}
    PersonKeeper operator=(const PersonKeeper &);
public:
    static PersonKeeper & intance()
    {
        static PersonKeeper PK;
        return PK;
    }
    // методы класса PersonKeeper
    Stack<Person> readPersons(std::fstream&); //будет возвращает стек, который уже заполнен ФИО
    void wridePerson(const Stack<Person> &); //будет записывать в поток из стека ФИО
};

#endif // PERSONKEEPER_H
