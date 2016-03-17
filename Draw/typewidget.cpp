#include "typewidget.h"
#include<QMouseEvent>
#include<QPainter>
#include<QDebug>
#include<QFileDialog>
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

void TypeWidget::save(const QString &fileName)
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QTextStream in(&file);
    for(int i = 0; i<m_childItems.count(); i++)
    {
        GraphItem* item = m_childItems.at(i);
        item->save(in);
    }
}
#include<QThread>

void TypeWidget::open(const QString &fileName)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd())
    {
        GraphType type;
        int val;
        in>>val;
        type = (GraphType)val;
        if(type == gLine)
        {
            GraphItem* line = new GraphLine();
            line->load(in);
            m_childItems.append(line);
        }
        else if(type == gRect)
        {
            GraphItem* line = new GraphRect();
            line->load(in);
            m_childItems.append(line);
        }
        else if(type == gEllipse)
        {
            GraphItem* line = new GraphEllipse();
            line->load(in);
            m_childItems.append(line);
        }
        else if(type == gImage)
        {
            GraphItem* item = new GraphImage();
            item->load(in);
            m_childItems.append(item);
        }
//        QThread::sleep(1);
    }
    update();
}

void TypeWidget::paintEvent(QPaintEvent *e)
{
    QPainter paint(this);

    paint.fillRect(this->rect(),Qt::white);
    paint.setRenderHint(QPainter::Antialiasing);

    for(int i = 0; i< m_childItems.count(); i++)
    {
        GraphItem* item = m_childItems.at(i);
        item->paint(&paint);
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
    else if(m_type==Rect || m_type == Image)
    {
        if(m_buer)
        {
            QPen pen;
            pen.setWidth(m_dow->getWidth());
            paint.setPen(pen);
            if(m_type == Rect)
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
        GraphLine *gl = new GraphLine();
        gl->setLine(line);
        QPen pen;
        pen.setColor(m_dow->color());
        pen.setWidth(m_dow->getWidth());
        gl->setPen(pen);
        m_childItems.append(gl);
    }
    else if(m_type==Rect)
    {
        QRect r(m_p1,m_p2);
        GraphRect *gr = new GraphRect;
        gr->setColor(m_dow->color());
        gr->setRect(r);
        QPen pen;
        pen.setWidth(m_dow->getWidth());
        gr->setPen(pen);
        m_childItems.append(gr);
    }
    else if(m_type==Ellipse)
    {
        QRect r(m_p1,m_p2);
        GraphEllipse *ge = new GraphEllipse;
        ge->setColor(m_dow->color());
        ge->setRect(r);
        QPen pen;
        pen.setWidth(m_dow->getWidth());
        ge->setPen(pen);
        m_childItems.append(ge);
    }
    else if(m_type==Image)
    {
        GraphImage *gi = new GraphImage;
        gi->setpoint(m_p1);
        QRect r(m_p1, m_p2);
        QString str=QFileDialog::getOpenFileName();
        gi->setImage(QImage(str).scaled(r.size()));
        m_childItems.append(gi);
    }
    update();
}

Thread::Thread(QObject *parent):QThread(parent)
{

}

Thread::Thread(const QString &fileName, TypeWidget *tw, QObject *parent)
    :QThread(parent)
{
    m_fileName = fileName;
    m_tw = tw;
}

void Thread::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

void Thread::setTypeWidget(TypeWidget *tw)
{
    m_tw = tw;
}
void Thread::run()
{
    if(m_tw)
        m_tw->open(m_fileName);
    this->deleteLater();
}
