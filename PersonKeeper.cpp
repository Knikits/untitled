#include "PersonKeeper.h"

Stack<Person> PersonKeeper::readPersons()
{
    this->stream->exceptions(std::ios_base::eofbit);
    std::string FIO[3];
    Stack<Person> stack;
    for (; ;)
    {
        for (int i = 0; i < 3; i++)
        {
            try
            {
                *this->stream >> FIO[i];
            }
            catch (const std::ios_base::failure&)
            {
                return stack;
            }
        }
         stack.Push(Person(FIO[0], FIO[1], FIO[2]));
     }
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
