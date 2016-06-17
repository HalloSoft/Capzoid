#include "triggerwidget.h"
#include "ui_triggerwidget.h"

TriggerWidget::TriggerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TriggerWidget)
{
    ui->setupUi(this);

    bool isConnected = false; Q_UNUSED(isConnected);
    isConnected = connect(ui->buttonCapture, SIGNAL(clicked()), this, SIGNAL(triggered())); Q_ASSERT(isConnected);
}

TriggerWidget::~TriggerWidget()
{
    delete ui;
}
