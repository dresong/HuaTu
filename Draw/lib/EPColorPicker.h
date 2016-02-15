#ifndef EPCOLORPICKER_H
#define EPCOLORPICKER_H

#include <QPushButton>
#include <QString>
#include <QColor>

#include <QEvent>
#include "EPColorPickerPopup.h"

class EPColorPicker : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QColor col READ currentColor WRITE setCurrentColor)
    Q_PROPERTY(bool withColorDialog READ colorDialogEnabled WRITE setColorDialogEnabled)
public:
    EPColorPicker(QWidget *parent = 0, bool enableColorDialog = true);

    ~EPColorPicker();

    void insertColor(const QColor &color, const QString &text = QString::null);
    QColor currentColor() const;
    bool colorDialogEnabled() const;

public Q_SLOTS:
    void setCurrentColor(const QColor &col, const QString &text = QString::null);
    void setColorDialogEnabled(bool enabled);

Q_SIGNALS:
    void colorChanged(const QColor &);

protected:
    void paintEvent(QPaintEvent *e);

private Q_SLOTS:
    void buttonPressed(bool toggled);
    void popupClosed();

private:
    EPColorPickerPopup *popup;
    QColor col;
    bool withColorDialog;
    bool dirty;
};
#endif // EPCOLORPICKER_H
