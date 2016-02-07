#include "window.h"
#include "QMenu"
#include "QMenuBar"
#include "QToolBar"
Window::Window(QMainWindow *parent):
    QMainWindow(parent)
{
    resize(400,300);
    m_menubar=this->menuBar();
    connect(m_menubar, SIGNAL(triggered(QAction*)),this, SLOT(slotAction(QAction*)));

    //fileMenu
    m_fileMenu=new QMenu();
    m_fileMenu->setTitle("File");
    m_actNew=new QAction(0);
    m_actNew->setText("New");
    QIcon Inew(":/Icon/FileNew.png");
    m_actNew->setToolTip("chuang jian wenjian");
    m_actNew->setIcon(Inew);
    m_fileMenu->addAction(m_actNew);
    m_menubar->addMenu(m_fileMenu);

    m_actOpen = new QAction(0);
    m_actOpen->setText("Open");
    QIcon Iopen(":/Icon/FileOpen.png");
    m_actOpen->setIcon(Inew);
    m_fileMenu->addAction(m_actOpen);

    m_actSave=new QAction(0);
    m_actSave->setText("Save");
    QIcon Isave(":/Icon/FileSave.png");
    m_actSave->setIcon(Isave);

    m_fileMenu->addAction(m_actSave);

    m_actExit =new QAction(0);
    m_actExit->setText("Exit");
    m_fileMenu->addAction(m_actExit);

    //editMenu
    m_editMenu=new QMenu();
    m_editMenu->setTitle("Edit");
    m_menubar->addMenu(m_editMenu);
    //boolBar
    tool=new QToolBar();
    tool->addAction(m_actNew);
    tool->addAction(m_actSave);
    connect(tool, SIGNAL(actionTriggered(QAction*)), this, SLOT(slotAction(QAction*)));
    this->addToolBar(tool);
}
#include <QDebug>
void Window::slotAction(QAction *action)
{
    qDebug()<<Q_FUNC_INFO<< action->text();
}
