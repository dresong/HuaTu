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

void TypeWidget::setWindow(Window *window)
{
    m_dow = window;
}

void TypeWidget::paintEvent(QPaintEvent *e)
{
    QPainter paint(this);

    paint.fillRect(this->rect(),Qt::white);
    paint.setRenderHint(QPainter::Antialiasing);

    for(int i = 0; i< m_Lines.count(); i++)
    {
        GraphLine line = m_Lines.at(i);
        line.paint(&paint);
    }
//Rect
    for(int i=0; i<m_Rects.count(); i++)
    {
        GraphRect rect = m_Rects.at(i);
        rect.paint(&paint);
    }
//Ellipse
    for(int i=0; i<m_Ellipses.count(); i++)
    {
        GraphEllipse ellipse = m_Ellipses.at(i);
        ellipse.paint(&paint);
    }
    if(m_type==Line)
    {
        if(m_buer)
        {

            QPen pen;
            pen.setWidth(m_dow->getWidth());
            paint.setPen(pen);
            paint.drawLine(QLine(m_p1,m_p2));
        }
    }
    else if(m_type==Rect)
    {
        if(m_buer)
        {
            QPen pen;
            pen.setWidth(m_dow->getWidth());
            paint.setPen(pen);
            paint.setBrush(m_dow->color());
            paint.drawRect(QRect(m_p1,m_p2));
        }
    }
    else if(m_type==Ellipse)
    {
        if(m_buer)
        {
            QPen pen;
            pen.setWidth((m_dow->getWidth()));
            paint.setPen(pen);
            paint.setBrush(m_dow->color());
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
        GraphLine gl;
        gl.setLine(line);
        QPen pen;
        pen.setColor(m_dow->color());
        pen.setWidth(m_dow->getWidth());
        gl.setPen(pen);
        m_Lines.append(gl);
    }
    else if(m_type==Rect)
    {
        QRect r(m_p1,m_p2);
        GraphRect gr;
        gr.setColor(m_dow->color());
        gr.setRect(r);
        QPen pen;
        pen.setWidth(m_dow->getWidth());
        gr.setPen(pen);
        m_Rects.append(gr);
    }
    else if(m_type==Ellipse)
    {
        QRect r(m_p1,m_p2);
        GraphEllipse ge;
        ge.setColor(m_dow->color());
        ge.setEllipse(r);
        QPen pen;
        pen.setWidth(m_dow->getWidth());
        ge.setPen(pen);
        m_Ellipses.append(ge);
    }
    update();
}
