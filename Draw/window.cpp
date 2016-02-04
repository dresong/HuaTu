#include "window.h"
#include "QMenu"
#include "QMenuBar"
#include "QToolBar"
Window::Window(QMainWindow *parent):
    QMainWindow(parent)
{
    resize(400,300);
    m_menubar=this->menuBar();

    m_menu=new QMenu();
    m_menu->setTitle("File");

    m_actNew=new QAction(0);
    m_actNew->setText("New");
    m_menu->addAction(m_actNew);
    m_menubar->addMenu(m_menu);

    tool=new QToolBar();
    tool->addAction(m_actNew);
    this->addToolBar(tool);
}
