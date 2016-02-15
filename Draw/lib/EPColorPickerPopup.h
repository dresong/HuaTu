#ifndef EPCOLORPICKERPOPUP_H
#define EPCOLORPICKERPOPUP_H

#include <QPainter>
#include <QPushButton>
#include <QMap>
#include <QLabel>

class EPColorPickerItem;

class EPColorPickerPopup : public QFrame
{
    Q_OBJECT

public:
    EPColorPickerPopup(QWidget *parent = 0);
    EPColorPickerPopup(bool withCustomColor, bool withColorDialog, QWidget *parent = 0);
    ~EPColorPickerPopup();

    // ���õ�ǰ��ɫ
    void setCurrentColor(const QColor & color, const QString &text = QString::null);
    // ����ѡ������ɫ
    QColor lastSelected() const;
    // ��ʾ�������¼�ѭ��
    void exec();

    bool withCustomColor() const;
    void setWithCustomColor(bool b);
    bool withColorDialog() const;
    void setWithColorDialog(bool b);

    // ��ָ��λ����ʾ������ɫѡ�񴰿ڲ�����ѡ������ɫ
    static QColor getColor(const QPoint &pos, bool allowCustomColors = true);

signals:
    void selected(const QColor &, const QString &);
    void hid();

public slots:
    void getColorFromDialog();

protected slots:
    void updateSelected();

protected:
    void keyPressEvent(QKeyEvent *e);
    void showEvent(QShowEvent *e);
    void hideEvent(QHideEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    void init();
    void initColorItems();
    void regenerateGrid();
    void selectItem(EPColorPickerItem *item);
    void selectItem(int index);
    void setItemFocus(int index);

    // ������ɫ
    void insertColor(const QColor &col, const QString &text = QString::null, int index = -1);
    // ����ָ������ɫ��
    EPColorPickerItem *find(const QColor &color) const;
    // ��������������ɫ
    QColor color(int index) const;

private:
    int m_columns;
    QList<EPColorPickerItem *> m_items;             // 8X5 ��������ɫ, 8 ��������ɫ
    QFrame *m_seperator;
    QFrame *m_seperator2;
    class EPColorPickerButton *m_moreButton;
    class QVBoxLayout *m_vbox;
    class QGridLayout *m_grid;
    class QGridLayout *m_grid_cc;
    class QEventLoop *m_eventLoop;
    QColor m_lastSelected;
    bool m_withCustomColor;
    bool m_withColorDialog;
    int m_firstCustom;
    int m_lastCustom;
    int m_currCustom;
};

/**** EPColorPickerItem *********************************************/

class EPColorPickerItem : public QFrame
{
    Q_OBJECT
public:
    EPColorPickerItem(const QColor &color = Qt::white, const QString &text = QString::null, QWidget *parent = 0);
    ~EPColorPickerItem();

    const QColor & color() const;
    const QString &  text() const;

    bool isSelected() const;
    void setSelected(bool);

signals:
    void clicked();

public slots:
    void setColor(const QColor &color, const QString &text = QString());

protected:
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    QColor  m_color;
    QString m_text;
    bool    m_selected;
};

/**** EPColorPickerButton *******************************************/

class EPColorPickerButton : public QFrame
{
    Q_OBJECT

public:
    EPColorPickerButton(QWidget *parent);

signals:
    void clicked();

protected:
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);
    virtual void paintEvent(QPaintEvent *e);
};

#endif // EPCOLORPICKERPOPUP_H
