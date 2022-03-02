#include <QCoreApplication>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for(int i=0;i<11;i++)
        //тут должно быть заполнение стека

    for(int i=0; i<12; i++)
        //"опустошение" стека
    return a.exec();
}
