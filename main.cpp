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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa

    for(int i=0;i<11;i++)
        //тут должно быть заполнение стека

=======
    Stack<int> stack; //создаём стек
=======
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
    return a.exec();
}
