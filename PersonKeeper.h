#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include "Stack.h"
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
};

#endif // PERSONKEEPER_H
