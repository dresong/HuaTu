#include "graphline.h"

GraphLine::GraphLine()
{

}

void GraphLine::paint(QPainter *painter)
{
    painter->setPen(m_pen);
    painter->drawLine(m_line);
}

void GraphLine::setLine(QLine line)
{
    m_line = line;
}

void GraphLine::setPen(const QPen &pen)
{
    m_pen = pen;
}


GraphRect::GraphRect()
{
    m_color = Qt::red;
}

void GraphRect::paint(QPainter *painter)
{
    painter->save();
    painter->setPen(m_pen);
    painter->setBrush(m_color);
    painter->drawRect(m_rect);
    painter->restore();
}

void GraphRect::setRect(QRect rect)
{
    m_rect = rect;
}

void GraphRect::setPen(const QPen& pen)
{
    m_pen = pen;
}

void GraphRect::setColor(const QColor &color)
{
    m_color = color;
}


GraphEllipse::GraphEllipse()
{

}

void GraphEllipse::paint(QPainter *painter)
{
    painter->setPen(m_pen);
    painter->setBrush(m_color);
    painter->drawEllipse(m_ellipse);
}

void GraphEllipse::setEllipse(QRect ellipse)
{
    m_ellipse = ellipse;
}

void GraphEllipse::setPen(const QPen &pen)
{
    m_pen = pen;
}

void GraphEllipse::setColor(const QColor &color)
{
    m_color = color;
}
