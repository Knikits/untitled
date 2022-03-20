#include <QCoreApplication>
#include <QDebug>
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa

using namespace std;
=======
#include <Stack.h>
#include <fstream>
#include "PersonKeeper.h"
#include "Person.h"
>>>>>>> main

//сначала создаём функции, и только потом пишем их содержимое
void cheakread();

void cheakread()
{
    Stack<Person> stack;
    stack.Push(Person("Меркушев Корнелий Оскарович"));
    stack.Push(Person("Савельев Юлий Алексеевич"));
    stack.Push(Person("Субботин Виссарион Фролович"));
    std::fstream stream("D:\\Учёба\\ТГУ\\Lab_1\\FIO.txt", std::ios::out);
    try
    {
        if(!stream.is_open())
            throw std::ios_base::failure("Error1");
    }
    catch (std::ios_base::failure& e)
    {
        qWarning() << e.what();
    }
    PersonKeeper::instance(&stream).writePersons(stack);
    if (stream.is_open())
        stream.close();

    stream.open("D:\\Учёба\\ТГУ\\Lab_1\\FIO.txt", std::ios::in);
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
        qDebug() << stack2.Pop().String() << '\n';
    }
}

void checkexceptionstack();

void checkexceptionstack()
{
    Stack<int> stack; //создаём экземпляр класса Stack
    for(int i=0; i<11; i++)
        stack.Push(i); //заполнение стека
    for(int i=0; i<12; i++)
        qDebug() << stack.Pop() << ' '; //опустошение стека с исключением, когда чисел больше нет
}


//главная функция
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa

    for(int i=0;i<11;i++)
        //тут должно быть заполнение стека

=======
    Stack<int> stack; //создаём стек
=======
=======
    cheakread();
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa
>>>>>>> f of cheakread
    /*Stack<int> stack; //создаём стек
>>>>>>> main
    for(int i=0; i<11;i++)
        stack.Push(i); //заполнение стека
>>>>>>> Remarks2
    for(int i=0; i<12; i++)
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa
        //"опустошение" стека
=======
        qDebug() << stack.Pop() << ' '; //"опустошение" стека*/
>>>>>>> main
=======
    //checkexceptionstack();
>>>>>>> main2
    return a.exec();
}
