#include "typewidget.h"
#include<QMouseEvent>
#include<QPainter>
TypeWidget::TypeWidget(QWidget *parent) :
    QWidget(parent)
{
    m_type=None;
}

void TypeWidget::setType(Type type)
{
    m_type=type;
}

void TypeWidget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.fillRect(this->rect(),Qt::white);
    if(m_type==Line)
    {
        paint.drawLine(m_p1,m_p2);
    }
    else if(m_type==Rect)
    {
        paint.drawRect(QRect(m_p1,m_p2));
    }
    else if(m_type==Ellipse)
    {
        paint.drawEllipse(QRect(m_p1,m_p2));
    }
}

void TypeWidget::mousePressEvent(QMouseEvent *e)
{
    m_p1=e->pos();
}

void TypeWidget::mouseMoveEvent(QMouseEvent *e)
{
    m_p2=e->pos();
    update();
}

void TypeWidget::mouseReleaseEvent(QMouseEvent *e)
{

}
