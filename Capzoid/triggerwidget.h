#ifndef TRIGGERWIDGET_H
#define TRIGGERWIDGET_H

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

signals:
    void triggered();

private:
    Ui::TriggerWidget *ui;
};

#endif // TRIGGERWIDGET_H
