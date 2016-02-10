#include "typewidget.h"
#include<QMouseEvent>
#include<QPainter>
TypeWidget::TypeWidget(QWidget *parent) :
    QWidget(parent)
{
    m_type=None;
    m_buer=false;
}

void TypeWidget::setType(Type type)
{
    m_type=type;
}

void TypeWidget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.fillRect(this->rect(),Qt::white);
//Line
    for(int i=0; i<m_Lines.count(); i++)
    {
        QLine line=m_Lines.at(i);
        paint.drawLine(line);
    }
//Rect
    for(int i=0; i<m_Rects.count(); i++)
    {
        QRect t=m_Rects.at(i);
        paint.drawRect(t);
    }
//Ellipse
    for(int i=0; i<m_Ellipses.count(); i++)
    {
        QRect r=m_Ellipses.at(i);
        paint.drawEllipse(r);
    }
    if(m_type==Line)
    {
        if(m_buer)
        {
            paint.drawLine(QLine(m_p1,m_p2));
        }
    }
    else if(m_type==Rect)
    {
        if(m_buer)
        {
            paint.drawRect(QRect(m_p1,m_p2));
        }
    }
    else if(m_type==Ellipse)
    {
        if(m_buer)
        {
            paint.drawEllipse(QRect(m_p1,m_p2));
        }
    }
}

void TypeWidget::mousePressEvent(QMouseEvent *e)
{
    m_buer=true;
    m_p1=e->pos();
}

void TypeWidget::mouseMoveEvent(QMouseEvent *e)
{
    m_p2=e->pos();
    update();
}

void TypeWidget::mouseReleaseEvent(QMouseEvent *e)
{
    m_buer=false;
    m_p2=e->pos();
    if(m_type==Line)
    {
        QLine line(m_p1,m_p2);
        m_Lines.append(line);
    }
    else if(m_type==Rect)
    {
        QRect r(m_p1,m_p2);
        m_Rects.append(r);
    }
    else if(m_type==Ellipse)
    {
        QRect r(m_p1,m_p2);
        m_Ellipses.append(r);
    }
    update();
}
