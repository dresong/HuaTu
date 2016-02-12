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

class GraphRect : public GraphItem
{
public:
    GraphRect();
    virtual void paint(QPainter *painter);
    GraphType type()
    {
        return gRect;
    }
    void setRect(QRect rect);
    void setPen(const QPen &pen);
    void setColor(const QColor &color);

    //save
    void save(QTextStream &ts);
    void load(QTextStream &ts);
protected:
    QRect m_rect;
    QPen m_pen;
    QColor m_color;
};

class GraphEllipse : public GraphRect
{
public:
    GraphEllipse();
    void paint(QPainter *painter);
    GraphType type()
    {
        return gEllipse;
    }
};

class GraphImage : public GraphItem
{
public:
    GraphImage()
    {

    }
    GraphType type()
    {
        return gImage;
    }
    void setImage(const QImage& img)
    {
        m_image = img;
    }
    void paint(QPainter* painter);

private:
    QImage m_image;
};

#endif // GRAPHLINE_H
