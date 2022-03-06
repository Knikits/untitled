#ifndef STACK_H
#define STACK_H
#include "estackexceptions.h"



<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa
=======
template<typename T>
T Stack<T>::Pop()
{
    try
    {
        if (top == nullptr) throw EStackEmpty(); //при условии, что стек пуст,
        //должно генерироваться исключение класса EStackEmpty(наследник класса EStackException)
    }
    catch (const EStackEmpty& e)
    {
        qWarning(e.what());
    }
    if (top->next == nullptr)
    {
        T value = top->value;
        delete top;
        top = nullptr;
        return value;
    }
    Node* newTop = top->next;
    T return_value = top->value;
    delete top;
    top = newTop;
    size--;
    return return_value;
}

template<typename T>
int Stack<T>::Len()
{
    return size;
}
>>>>>>> Remark

#endif // STACK_H
