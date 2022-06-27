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
    // В задании подразумевается, что ни одно поле ФИО не может быть пустым
    //stack.Push(Person("Volkov", "Denis", "Vladimirovich"));
    //stack.Push(Person("Nosova-Morozova", "Svetlana", "Kupriyanovna")); // ввожу 3 ФИО в стек
    //stack.Push(Person("Kazakova", "Mariana", "Denisovna"));

    //Тестирование этого класса заключается в попытках передать ему разные входные данные и посмотреть, как он на это отреагирует.

    //При помещении данных в виде чисел (без “”) не даёт отработать программе, так как мы должны передавать std::string.

    //При добавлении лишних пробелов или табов (перед или после слов) результат так же остаётся неизменным.
    /*
    stack.Push(Person("Volkov", "   Denis", "Vladimirovich"));
    stack.Push(Person("Nosova", "Svetlana", "Kupriyanovna            "));  // ввожу 3 ФИО в стек
    stack.Push(Person("Kazakova", " Mariana", "Denisovna"));
    */

    //При добавлении в стек пустых полей ФИО на выводе мы не увидим второй строки, что является допустимым,
    //так как если мы не ничего не введём, то мы ничего и не увидим по итогу.
    /*
    stack.Push(Person("Volkov", "Denis", "Vladimirovich"));
    stack.Push(Person("", "", "")); // ввожу 3 ФИО в стек
    stack.Push(Person("Kazakova", "Mariana", "Denisovna"));
    */

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
    Stack<Person> stack2 = PersonKeeper::instance(&stream).readPersons(); // создаём переменную типа стек и присваем то, что придёт из файла

    for (; 0 < stack2.Len();)
    {
        qDebug() << stack2.Pop().String().get() << '\n'; // записываем фио, переходим новую строку и прочитываем из файла наши ФИО
    }
}


void checkexceptionstack(); // для первой части лабы
void checkexceptionstack()
{
    // классический вариант работы
    Stack<int> stack; //создаём экземпляр класса Stack
    for (int i = 1; i < 21; i++)
        stack.Push(i); //заполнение стека
    for (int i = 1; i < 22; i++)
        qDebug() << stack.Pop(); //опустошение стека с исключением, когда чисел больше нет

    // вариант, когда в стек пуст
    /*
    Stack<int> stack;
    stack.Pop();
    */

    // вариант, когда записываем в стек один символ
    /*
    Stack<int> A;
    A.Push(100);
    qDebug() << A.Pop();
    */

}


// Главная функция
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cheakread();
    //checkexceptionstack();
    return a.exec();
}
