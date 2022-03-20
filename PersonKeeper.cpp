#include "PersonKeeper.h"

Stack<Person> PersonKeeper::readPersons()
{

}

void PersonKeeper::writePersons(const Stack<Person> &input)
{
    Stack<Person> stack = input;
    for(; 0 < stack.Len();)
    {
        *this->stream << stack.Pop().String();
        if(stack.Len() != 0)
            stream->put('\n');
    }
    stream->close();
}
