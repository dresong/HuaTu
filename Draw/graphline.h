#ifndef GRAPHLINE_H
#define GRAPHLINE_H
#include<QPainter>
#include<QTextStream>

enum GraphType
{
    gLine,
    gRect,
    gEllipse,
    gImage
};

class GraphItem
{
public:
    virtual void paint(QPainter* painter) = 0;
    virtual void save(QTextStream &ts) = 0;
    virtual void load(QTextStream &ts) = 0;
    virtual GraphType type() = 0;
};

class GraphLine : public GraphItem
{
public:
    GraphLine();
    void paint(QPainter* painter);
    GraphType type()
    {
        return gLine;
    }

    void setLine(QLine line);
    void setPen(const QPen& pen);

    //save
    void save(QTextStream &ts);
    void load(QTextStream &ts);
private:
    QPen m_pen;
    QLine m_line;
};



#endif // GRAPHLINE_H
