#include<QDebug>
#include<QApplication>
#include<window.h>
#include <QProgressBar>
#include <QFile>
#include <QTextStream>
#include <QThread>

int main(int argc, char *argv[])
{
    qDebug()<<"--------------------";
    qDebug()<<"++++++++++++++++++++++";

    QApplication tion(argc,argv);

    Window *dow = new Window();
    qDebug()<<"dow =="<<&dow;
    dow->show();


    int array[8] = { 5,90,20,10,34, 657,897,23};

    QList<int> ints;
    for(int i = 0; i< 10000; i++)
    {
        int a = qrand();
//        qDebug()<<"a = "<<a;
        ints<<i;
    }

//    qDebug()<<ints;

    int max = ints[0];
    int index = 0;
    for(int i = 0; i<ints.count(); i++)
    {
        if(ints.at(i) > max)
        {
            max = ints.at(i);
            index = i;
        }
    }

//    qDebug()<<"max = "<<max;
//    qDebug()<<"index = "<<index;

//    QList<int> intss;
//    intss<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10;

//    QFile file("/home/linux/one.txt");
//    file.open(QIODevice::WriteOnly);
//    QTextStream in(&file);
//    QProgressBar bar;
//    bar.setMaximum(10);
//    bar.show();

//    for(int i = 0; i<intss.count(); i++)
//    {
//        in<<intss[i];
//        bar.setValue(i+1);
//        qApp->processEvents();
//        QThread::sleep(1);
//    }

    return tion.exec();
}
