#ifndef GRAPHLINE_H
#define GRAPHLINE_H
#include<QPainter>
class GraphLine
{
public:
    GraphLine();
    void paint(QPainter* painter);
    void setLine(QLine line);
    void setPen(const QPen& pen);
private:
    QPen m_pen;
    QLine m_line;
};

class GraphRect
{
public:
    GraphRect();
    void paint(QPainter *painter);
    void setRect(QRect rect);
    void setPen(const QPen &pen);
    void setColor(const QColor &color);
private:
    QRect m_rect;
    QPen m_pen;
    QColor m_color;
};

class GraphEllipse
{
public:
    GraphEllipse();
    void paint(QPainter *painter);
    void setEllipse(QRect ellipse);
    void setPen(const QPen &pen);
    void setColor(const QColor &color);

private:
    QRect m_ellipse;
    QPen m_pen;
    QColor m_color;
};

#endif // GRAPHLINE_H
