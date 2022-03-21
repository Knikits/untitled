#include <QCoreApplication>
#include <QDebug>
#include <Stack.h>
#include <fstream>
#include "PersonKeeper.h"
#include "Person.h"

//сначала создаём функции, а потом пишем их содержимое
void cheakread();

void cheakread()
{
    Stack<Person> stack;
    stack.Push(Person("Savelev Iulii Alekseevich"));
    stack.Push(Person("Nosova Svetlana Kupriyanovna"));
    stack.Push(Person("Kazakova Mariana Denisovna"));
    std::fstream stream("D:\\Lab_1\\FIO.txt", std::ios::out);
    try
    {
        if(!stream.is_open())
            throw std::ios_base::failure("Error1"); // если не открывается, выводим ошибку
    }
    catch (std::ios_base::failure& e)
    {
        qWarning() << e.what();
    }
    PersonKeeper::instance(&stream).writePersons(stack);
    if (stream.is_open())
        stream.close(); // и закрываем, если ещё открыт

    stream.open("D:\\Lab_1\\FIO.txt", std::ios::in);
    try
    {
        if(!stream.is_open())
            throw std::ios_base::failure("Error2");
    }
    catch (std::ios_base::failure& e)
    {
        qWarning() << e.what();
    }
    Stack<Person> stack2 = PersonKeeper::instance(&stream).readPersons();

    for (; 0 < stack2.Len();)
    {
        qDebug() << stack2.Pop().String() << '\n'; // записываем фио и на переходим новую строку
    }
}

/*
void checkexceptionstack();
void checkexceptionstack()
{
    Stack<int> stack; //создаём экземпляр класса Stack
    for(int i = 0; i < 11; i++)
        stack.Push(i); //заполнение стека
    for(int i = 0; i < 12; i++)
        qDebug() << stack.Pop() << ' '; //опустошение стека с исключением, когда чисел больше нет
}
*/

// Главная функция
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cheakread(); // функция чтения
    //checkexceptionstack();
    return a.exec();
}
