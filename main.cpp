#include <QCoreApplication>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
<<<<<<< 3124eb98bf561978b0064eadc173fe55c4b876aa

    for(int i=0;i<11;i++)
        //тут должно быть заполнение стека

=======
    Stack<int> stack; //создаём стек
    for(int i=0; i<11;i++)
        stack.Push(i); //заполнение стека
>>>>>>> Remarks2
    for(int i=0; i<12; i++)
        //"опустошение" стека
    return a.exec();
}
