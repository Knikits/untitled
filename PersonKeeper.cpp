#include "PersonKeeper.h"
#include "string.h"
// преобразование потока в поле класса PersonKeeper

void PersonKeeper::writePersons(const Stack<Person> &input) // стек не должен измениться
{
    Stack<Person> stack = input;
    for(; 0 < stack.Len();)
    {
        *this->stream << stack.Pop().String(); // вытаскиваем из стека ФИО
        if(stack.Len() != 0)
            stream->put('\n'); // переходим на новую строку
    }
    stream->close();
}


bool is_number(const std::string& s)
{
    int check;
    for (int j = 0; j < s.length(); j++)
    {
        check = isdigit(s[j]);
    }
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}


Stack<Person> PersonKeeper::readPersons()
{
    this->stream->exceptions(std::ios_base::eofbit); // генерация исключения
    Stack<Person> stack;
    std::string fio[3];
    for (; ;)
    {
        for (int i = 0; i < 3; i++)
        {
            try
            {
                *this->stream >>  fio[i]; // заполняем fio[i] ФИО
            }
            catch (const std::ios_base::failure&)
            {
                stack.Push(Person( fio[0],  fio[1],  fio[2]));
                return stack;
            }
        }
        if (is_number(fio[0]))
            fio[0] = "Error";
        stack.Push(Person( fio[0],  fio[1],  fio[2])); // отправляем в стек фамилию имя отчество
     }
}
