#include "window.h"
#include "QMenu"
#include "QMenuBar"
#include "QToolBar"
#include "typewidget.h"
Window::Window(QMainWindow *parent):
    QMainWindow(parent)
{
    resize(800,600);
    m_menubar=this->menuBar();
    connect(m_menubar, SIGNAL(triggered(QAction*)),this, SLOT(slotAction(QAction*)));

    //fileMenu
    m_fileMenu=new QMenu();
    m_fileMenu->setTitle("File");
    m_actNew=new QAction(0);
    m_actNew->setText("New");
    QIcon Inew(":/Icon/FileNew.png");
//    m_actNew->setToolTip("chuang jian wenjian");
    m_actNew->setIcon(Inew);
    m_fileMenu->addAction(m_actNew);
    m_menubar->addMenu(m_fileMenu);

    m_actOpen = new QAction(0);
    m_actOpen->setText("Open");
    QIcon Iopen(":/Icon/FileOpen.png");
    m_actOpen->setIcon(Iopen);
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
    m_actMove=new QAction(QIcon(":/Icon/EditMove.png"), "Move",this);
    m_actMove->setCheckable(true);
    //    m_actMove->setText("Move");
//    QIcon Imove(":/Icon/EditMove.png");
//    m_actMove->setIcon(Imove);
    m_editMenu->addAction(m_actMove);

    //typeMenu
    m_typeMenu = new QMenu();
    m_typeMenu->setTitle("Type");
    m_menubar->addMenu(m_typeMenu);
    m_actLine=new QAction(QIcon(":/Icon/DrawLine.png"),"Line",this);
    m_typeMenu->addAction(m_actLine);
    m_actLine->setCheckable(true);

    m_actRect=new QAction(QIcon(":/Icon/DrawRectangle.png"),"Rect",this);
    m_typeMenu->addAction(m_actRect);
    m_actRect->setCheckable(true);

    m_actEllipse=new QAction(QIcon(":/Icon/DrawEllipse.png"),"Ellipse",this);
    m_typeMenu->addAction(m_actEllipse);
    m_actEllipse->setCheckable(true);

    //boolBar
    tool=new QToolBar();
    tool->addAction(m_actNew);
    tool->addAction(m_actOpen);
    tool->addAction(m_actSave);
    tool->addSeparator();
    tool->addAction(m_actMove);
    tool->addSeparator();
    tool->addAction(m_actLine);
    tool->addAction(m_actRect);
    tool->addAction(m_actEllipse);
    //shurukuang
    m_spinBox = new QSpinBox(tool);

    tool->addWidget(m_spinBox);
    m_spinBox->setMaximumWidth(100);
    m_spinBox->setMinimumWidth(100);
    connect(tool, SIGNAL(actionTriggered(QAction*)), this, SLOT(slotAction(QAction*)));
    this->addToolBar(tool);

    m_tw = new TypeWidget();
    m_tw->setWindow(this);
    this->setCentralWidget(m_tw);

}

int Window::getWidth()
{
    int v = m_spinBox->value();
    return v;
}

#include <QDebug>
void Window::slotAction(QAction *action)
{
//    qDebug()<<Q_FUNC_INFO<< action->text();
    qDebug()<<m_actEllipse->isChecked();
    if(action==m_actMove)
    {
        m_actLine->setChecked(false);
        m_actRect->setChecked(false);
        m_actEllipse->setChecked(false);

    }
    else if(action==m_actLine)
    {
        m_actMove->setChecked(false);
        m_actRect->setChecked(false);
        m_actEllipse->setChecked(false);
        m_tw->setType(Line);
        if(!m_actLine->isChecked())
        {
            m_tw->setType(None);
            m_actMove->setChecked(true);
        }
    }
    else if(action==m_actRect)
    {
        m_actLine->setChecked(false);
        m_actMove->setChecked(false);
        m_actEllipse->setChecked(false);
        m_tw->setType(Rect);
        if(!m_actRect->isChecked())
        {
            m_tw->setType(None);
            m_actMove->setChecked(true);
        }
    }
    else if(action==m_actEllipse)
    {
        m_actLine->setChecked(false);
        m_actRect->setChecked(false);
        m_actMove->setChecked(false);
        m_tw->setType(Ellipse);
        if(!m_actEllipse->isChecked())
        {
            m_tw->setType(None);
            m_actMove->setChecked(true);
        }
    }
}
