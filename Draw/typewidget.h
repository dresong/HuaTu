#ifndef TYPEWIDGET_H
#define TYPEWIDGET_H

#include <QWidget>
#include <window.h>
#include <graphline.h>

enum Type
{
    None,
    Line,
    Rect,
    Ellipse
};

class TypeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TypeWidget(QWidget *parent = 0);
    void setType(Type type);
    void setWindow(Window* window);
    void save(const QString& fileName);
    void open(const QString& fileName);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
signals:

public slots:
private:
    QPoint m_p1,m_p2;
    Type m_type;
    bool m_buer;
    Window *m_dow;    
    QList<GraphItem*> m_childItems;

};

#endif // TYPEWIDGET_H
