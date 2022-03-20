#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H
#include <string.h>

class EStackException // класс исключений для стека (родитель)
{
private:
    char* message; // сообщение
public:
    EStackException(const char* arg_message) // конструктор с параметром
    {
        message = new char[strlen(arg_message) + 1];
        for (int j = 0; j < strlen(arg_message) + 1; j++)
                            message[j] = arg_message[j];
    }
    EStackException(const EStackException& arg) // конструктор копирования
    {
        message = new char[strlen(arg.message) + 1];
        for (int j = 0; j < strlen(arg.message) + 1; j++)
                            message[j] = arg.message[j];
    }
    ~EStackException() // деструктор
    {
        delete message;
    }
    const char* what() const { return message; }
};

// Этот класс нужен для обработки исключений (когда стек пуст)
class EStackEmpty : public EStackException // класс EStackEmpty является потомком класса EStackException
{
public: // наследуется только паблик!
    explicit EStackEmpty(const char* arg = "Stack is Empty") : EStackException(arg) {}
    explicit EStackEmpty(const EStackEmpty& arg) : EStackException(arg) {}
};

#endif // ESTACKEXCEPTION_H
