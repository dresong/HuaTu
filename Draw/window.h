#ifndef WINDOW_H
#define WINDOW_H
#include <QMainWindow>

class Window : public QMainWindow
{
public:
    explicit Window(QMainWindow *parent=0);
private:
    QMenuBar *m_menubar;
    QMenu *m_menu;
    QAction *m_actNew;
    QToolBar *tool;

};

#endif // WINDOW_H
