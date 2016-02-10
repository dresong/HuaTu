#ifndef TYPEWIDGET_H
#define TYPEWIDGET_H

#include <QWidget>
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
    QList<QLine> m_Lines;
    QList<QRect> m_Rects;
    QList<QRect> m_Ellipses;
    bool m_buer;
};

#endif // TYPEWIDGET_H
