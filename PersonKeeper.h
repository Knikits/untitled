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
    std::fstream* stream = nullptr;
public:
    static PersonKeeper & instance(std::fstream* stream)
    {
        static PersonKeeper PK;
        PK.stream = stream;
        return PK;
    }
    // методы класса PersonKeeper
    Stack<Person> readPersons(); //будет возвращает стек, который уже заполнен ФИО
    void writePersons(const Stack<Person> &); //будет записывать в поток из стека ФИО
};

#endif // PERSONKEEPER_H