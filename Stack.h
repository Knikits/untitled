#ifndef STACK_H
#define STACK_H
#include <QDebug>
#include "EStackException.h"
#include <iostream>

// Класс стека - шаблонный

template<typename T>
class Stack
{
private:
    class Node // создан при помощи композиции
    {
    public:
        T value; // значение
        Node* next; // указатель на следующий элемент

        Node(T value, Node* next = nullptr)
        {
            this->value = value;
            this->next = next;
        }
    };
    Node* top = nullptr; // указатель на вершину стека
    int size = 0; // размер стека
public:
    void Push(T value); // предназначен для добавления узла на вершину стека
                        // принимает на вход новое значения из вершиы стека и ничего не возвращает
    T Pop(); // для вытаскивания значения из вершины стека
             // возвращает значение типа Т из вершины стека и ничего не принимает
    int Len(); // возвращает размер стека
    //добавляем конструкторы
    Stack<T>& operator=(const Stack<T>&); //присваивание
    Stack<T>(const Stack<T>& stack); //копирование
    Stack<T>(){};
};

template<typename T>
void Stack<T>::Push(T value)
{
    size++; // каждый раз увеличивается стек на один
    if (top == nullptr) // если вершина пуста
    {
        top = new Node(value); // то создаём новую вершину
        return;
    }
    Node* prevTop = top; // в противном случае смещается старая вершина
    top = new Node(value, prevTop); // создаётся новый узел
}

template<typename T>
T Stack<T>::Pop()
{
    try
    {
        if (size == 0) throw EStackEmpty(); //если стек пуст,
        //генерируется исключение класса EStackEmpty(наследник класса EStackException)
    }
    catch (EStackEmpty& e)
    {
        qWarning(e.what());
    }
    Node* newTop = top->next; // иначе запоминается следующий элемент после вершины
    T return_value = top->value; // и значение в этой вершине
    delete top; // чистим память в вершине
    top = newTop; // смещаем новую вершину
    size--; // уменьшается стек
    return return_value; // возвращаем значение старой вершины
}

template<typename T>
int Stack<T>::Len()
{
    return size; // возврат размера стека
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack) //реализация оператора присваивания
{
    Stack<T> inverse;
    Node *node = stack.top;
    for (int i = 0; i < stack.size; i++)
    {
        inverse.Push(node->value); // производим инверсию стека
        node = node->next;
    }
    node = inverse.top;
    for (int i = 0; i < stack.size; i++)
    {
        this->Push(node->value); // разворачиваем обратно
        node = node->next;
    }
    return *this;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &stack) // реализация конструктора копирования
{
    Stack<T> inverse;
    Node *node = stack.top;
    for (int i = 0; i < stack.size; i++)
    {
        inverse.Push(node->value); // производим инверсию стека
        node = node->next;
    }
    node = inverse.top;
    for (int i = 0; i < stack.size; i++)
    {
        this->Push(node->value); // разворачиваем обратно
        node = node->next;
    }
}

#endif // STACK_H
