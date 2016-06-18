#include "triggerwidget.h"
#include "ui_triggerwidget.h"

#include <QDebug>

TriggerWidget::TriggerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TriggerWidget)
{
    ui->setupUi(this);

    QValidator *intValidator = new QIntValidator(0, 60, this);
    ui->lineEditHours->setValidator(intValidator);
    ui->lineEditMinutes->setValidator(intValidator);
    QValidator *doubleValidator = new QDoubleValidator(0, 60, 2, this);
    ui->lineEditSeconds->setValidator(doubleValidator);

    bool isConnected = false; Q_UNUSED(isConnected);
    // buttons
    isConnected = connect(ui->buttonCapture, SIGNAL(clicked()), this, SIGNAL(triggered())); Q_ASSERT(isConnected);
    isConnected = connect(ui->buttoncontiniousStartStop, SIGNAL(clicked()), this, SLOT(toggleContiniousMode())); Q_ASSERT(isConnected);

    // modes
    isConnected = connect(ui->comboBoxTriggerKind, SIGNAL(activated(int)), ui->stackedWidget, SLOT(setCurrentIndex(int))); Q_ASSERT(isConnected);


    //triggers
    isConnected = connect(&captureTimer, SIGNAL(timeout()), this, SIGNAL(triggered())); Q_ASSERT(isConnected);

    ui->comboBoxTriggerKind->addItem(tr("Manual Mode"));
    ui->comboBoxTriggerKind->addItem(tr("Continious Mode"));

    setEnabled(false);
}

TriggerWidget::~TriggerWidget()
{
    delete ui;
}

void TriggerWidget::setEnabled(bool enable)
{
    ui->buttonCapture->setEnabled(enable);
    ui->buttoncontiniousStartStop->setEnabled(enable);
}

void TriggerWidget::toggleContiniousMode()
{
    QString mode = ui->buttoncontiniousStartStop->text();

    if(mode == "Start")
    {
        int hours = ui->lineEditHours->text().toInt();
        int minutes = ui->lineEditMinutes->text().toInt();
        float seconds = ui->lineEditSeconds->text().toFloat();
        int milliseconds = hours * 3600000 + minutes * 60000 + seconds * 1000.0;
        qDebug() << "Timer startet with" << milliseconds << "ms";
        captureTimer.start(milliseconds);
        ui->buttoncontiniousStartStop->setText("Stop");
    }
    else
    {
        captureTimer.stop();
        ui->buttoncontiniousStartStop->setText("Start");
    }
}

