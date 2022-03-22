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
    int n = 0;
    switch (n)
    {
    case 0:
        stack.Push(Person("Savelev Iulii Alekseevich"));
        stack.Push(Person("Nosova Svetlana Kupriyanovna")); // ввожу 3 ФИО в стек
        stack.Push(Person("Kazakova Mariana Denisovna"));;
        break;
    case 1:
        stack.Push(Person("Savelev Iulii Alekseevich"));
        stack.Push(Person("Nosova Svetlana Kupriyanovna"));
        stack.Push(Person("Kazakova Mariana Denisovna")); // ввожу 6 ФИО в стек
        stack.Push(Person("Kostryukov Nikita Sergeevich"));
        stack.Push(Person("Marshal Dmitryi Olegovich"));
        stack.Push(Person("Emeljanenko Denis Vladimirovich"));
        break;
    case 2:
        stack.Push(Person("Волков Владислав Николаевич"));
        stack.Push(Person("Степичев Николай Михайлович")); // ввожу 3 ФИО (на русском), ломается кодировка
        stack.Push(Person("Кондратенко Илья Никитович"));
        break;
    }
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
    PersonKeeper::instance(&stream).writePersons(stack); // далее записываю ФИО в файл по пути, указанному выше
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
        qDebug() << stack2.Pop().String() << '\n'; // записываем фио, переходим новую строку и прочитываем из файла наши ФИО
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
