#ifndef CONTOLWIDGET_H
#define CONTOLWIDGET_H

#include <QTimer>
#include <QWidget>

namespace Ui {
class ContolWidget;
}

class ControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWidget(QWidget *parent = 0);
    ~ControlWidget();

    void setImageCaptureEnabled(bool enable);

private slots:
    void toggleContiniousMode();

signals:
    void captureImage();

private:
    Ui::ContolWidget *ui;

    bool   isContiniousModeActive = false;
    QTimer shootTimer;
};

#endif // CONTOLWIDGET_H
