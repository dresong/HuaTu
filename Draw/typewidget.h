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
    QList<GraphLine> m_Lines;
    GraphLine* m_pLine;
    QList<GraphRect> m_Rects;
    QList<GraphEllipse> m_Ellipses;

    bool m_buer;
    Window *m_dow;

};

#endif // TYPEWIDGET_H
