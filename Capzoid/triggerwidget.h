#ifndef TRIGGERWIDGET_H
#define TRIGGERWIDGET_H

#include <QTimer>
#include <QWidget>

namespace Ui {
class TriggerWidget;
}

class TriggerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TriggerWidget(QWidget *parent = 0);
    ~TriggerWidget();

    void setEnabled(bool enable);

signals:
    void triggered();

private slots:
    void toggleContiniousMode();

private:
    Ui::TriggerWidget *ui;
    QTimer captureTimer;
};

#endif // TRIGGERWIDGET_H
