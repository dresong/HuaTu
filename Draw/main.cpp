#include<QDebug>
#include<QApplication>
#include<window.h>
int main(int argc, char *argv[])
{
    qDebug()<<"--------------------";
    qDebug()<<"++++++++++++++++++++++";

    QApplication tion(argc,argv);

    Window dow;
    dow.show();
    return tion.exec();
}
