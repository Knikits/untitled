#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include "Stack.h"
#include "Person.h"
#include <fstream>

//Реализация класса PersonKeeper с методами readPersons и writePersons
//Класс PersonKeeper реализован в соответствии с шаблоном Singleton
//instace() используется для того, чтобы пользоваться единственным экземпляром класса
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
    void writePersons(const Stack<Person> &); //будет брать стек с ФИО
};

#endif // PERSONKEEPER_H
