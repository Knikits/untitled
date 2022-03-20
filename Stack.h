#ifndef STACK_H
#define STACK_H
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa
#include "estackexceptions.h"

=======
#include <QDebug>
#include "EStackException.h"
#include <iostream>

//класс стека - шаблонный

template<typename T>
class Stack
{
private:
    class Node
    {
    public:
        T value;
        Node* next;
        Node(T value, Node* next = nullptr)
        {
            this->value = value;
            this->next = next;
        }
    };
    Node* top = nullptr;
    int size = 0;
public:
    void Push(T value);
    T Pop();
    int Len();
    //добавляем конструкторы
    Stack<T>& operator=(const Stack<T>&); //присваивание
    Stack<T>(const Stack<T>& stack); //копирование
    Stack<T>(){};
};
>>>>>>> Adding constructors in Stack

<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa
=======
template<typename T>
void Stack<T>::Push(T value)
{
    size++;
    if (top == nullptr)
    {
        top = new Node(value);
        return;
    }
    Node* prevTop= top;
    top = new Node(value, prevTop);
}
>>>>>>> Ready Stack.h

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

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack) //реализация оператора присваивания
{
    Stack<T> inverse;
    Node *node = stack.top;
    for (int i = 0; i < stack.size; i++)
    {
        inverse.Push(node->value);
        node = node->next;
    }
    node = inverse.top;
    for (int i = 0; i < stack.size; i++)
    {
        this->Push(node->value);
        node = node->next;
    }
    return *this;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &stack)
{
    Stack<T> inverse;
    Node *node = stack.top;
    for (int i = 0; i < stack.size; i++)
    {
        inverse.Push(node->value);
        node = node->next;
    }
    node = inverse.top;
    for (int i = 0; i < stack.size; i++)
    {
        this->Push(node->value);
        node = node->next;
    }
}

#endif // STACK_H
