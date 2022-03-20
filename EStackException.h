#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H
#include <string.h>

class EStackException
{
private:
    char* message;
public:
    EStackException(const char* arg_message)
    {
        message = new char[strlen(arg_message) + 1];
        strcpy(message, arg_message);
    }
    EStackException(const EStackException& arg)
    {
        message = new char[strlen(arg.message) + 1];
        strcpy(message, arg.message);
    }
    ~EStackException()
    {
        delete message;
    }
    const char* what() const { return message; }
};

class EStackEmpty : public EStackException
{
public:
    explicit EStackEmpty(const char* arg = "Stack is Empty") : EStackException(arg) {}
    explicit EStackEmpty(const EStackEmpty& arg) : EStackException(arg) {}
};

#endif // ESTACKEXCEPTION_H
