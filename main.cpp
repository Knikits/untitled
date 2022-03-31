#include <QCoreApplication>
#include <QDebug>
#include <Stack.h>
#include <fstream>
#include "PersonKeeper.h"
#include "Person.h"

//сначала создаём функции, а потом пишем их содержимое
void cheakread(); // для второй части лабы
void cheakread()
{
    Stack<Person> stack;
    int n = 1;
    switch (n)
    {
    case 0:
        stack.Push(Person("Savelev", "Iulii", "Alekseevich"));
        stack.Push(Person("Nosova", "Svetlana", "Kupriyanovna")); // ввожу 3 ФИО в стек
        stack.Push(Person("Kazakova", "Mariana", "Denisovna"));;
        break;
    case 1:
        stack.Push(Person("", "", ""));
        stack.Push(Person("Nosova", "-", "Kupriyanovna"));
        stack.Push(Person("Kazakova", "Mariana", "Denisovna")); // ввожу 6 ФИО в стек
        stack.Push(Person("Kostryukov", "-", "-"));
        stack.Push(Person("Marshal", "Dmitryi", "-"));
        stack.Push(Person("-", "Denis", "Vladimirovich"));
        break;
    }
    std::fstream stream("D:\\Lab_1\\FIO.txt", std::ios::out); // файл создаётся автоматически и далее заполняется
    try
    {
        if(!stream.is_open())
            throw std::ios_base::failure("Error1"); // если не открывается, выводим ошибку1
    }
    catch (std::ios_base::failure& e)
    {
        qWarning() << e.what();
    }
    PersonKeeper::instance(&stream).writePersons(stack); // далее записываю ФИО в файл по пути, указанному выше
    if (stream.is_open())
        stream.close(); // и закрываем

    stream.open("D:\\Lab_1\\FIO.txt", std::ios::in);
    try
    {
        if(!stream.is_open())
            throw std::ios_base::failure("Error2"); // если не открывается, выводим ошибку2
    }
    catch (std::ios_base::failure& e)
    {
        qWarning() << e.what();
    }
    Stack<Person> stack2 = PersonKeeper::instance(&stream).readPersons(); // создаём переменную типа стек и присваем то, что придёт из стека

    for (; 0 < stack2.Len();)
    {
        qDebug() << stack2.Pop().String() << '\n'; // записываем фио, переходим новую строку и прочитываем из файла наши ФИО
    }
}

/*
void checkexceptionstack(); // для первой части лабы
void checkexceptionstack()
{
    Stack<int> stack; //создаём экземпляр класса Stack
    for (int i = 1; i < 21; i++)
        stack.Push(i); //заполнение стека
    for (int i = 1; i < 22; i++)
        qDebug() << stack.Pop(); //опустошение стека с исключением, когда чисел больше нет
}
*/

// Главная функция
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cheakread();
    //checkexceptionstack();
    return a.exec();
}
