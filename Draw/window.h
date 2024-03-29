#ifndef WINDOW_H
#define WINDOW_H
#include <QMainWindow>
#include <QSpinBox>
#include "colorbutton.h"
class TypeWidget;

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QMainWindow *parent=0);
    int getWidth();
    QColor color();

public slots:
    void slotAction(QAction* action);

private:
    QMenuBar *m_menubar;
    QMenu *m_fileMenu;
    QMenu *m_editMenu;
    QMenu *m_typeMenu;
    QAction *m_actNew;
    QAction *m_actMove;
    QAction *m_actSave;
    QAction *m_actOpen;
    QAction *m_actExit;
    QAction *m_actLine;
    QAction *m_actRect;
    QAction *m_actImage;
    QAction *m_actString;
    QAction *m_actEllipse;

    QToolBar *tool;
    TypeWidget *m_tw;
    QSpinBox *m_spinBox;
    ColorButton *m_button;
};

#endif // WINDOW_H
