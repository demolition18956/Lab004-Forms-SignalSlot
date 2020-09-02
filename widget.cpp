#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    QObject::connect(ui->toolButton, &QToolButton::clicked, this, &Widget::PrintTool);
    QObject::connect(ui->toolButton_2, &QToolButton::clicked, this, &Widget::PrintTool);
    QObject::connect(ui->toolButton_3, &QToolButton::clicked, this, &Widget::PrintTool);
    QObject::connect(ui->toolButton_4, &QToolButton::clicked, this, &Widget::PrintTool);

    QObject::connect(ui->goButton, &QPushButton::clicked, this, &Widget::PrintGo);
    QObject::connect(ui->pauseButton, &QPushButton::clicked, this, &Widget::PrintPause);
    QObject::connect(ui->stopButton, &QPushButton::clicked, this, &Widget::PrintStop);

    QObject::connect(ui->bitButton, &QRadioButton::toggled, this, &Widget::UpdateBit);

    QObject::connect(ui->lineEdit, &QLineEdit::textChanged, this, &Widget::PrintText);
    QObject::connect(ui->clearButton, &QPushButton::clicked, ui->lineEdit, &QLineEdit::clear);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::PrintTool() {
   qDebug() << "\"Tool Button\"";
}

void Widget::PrintGo() {
    qDebug() << "\"Go\"";
}

void Widget::PrintPause() {
    qDebug() << "\"Pause\"";
}

void Widget::PrintStop() {
    qDebug() << "\"Stop\"";
}

void Widget::UpdateBit(bool bit) {
    qDebug() << "Bit Button is " << (int)bit;
    ui->bitLabel->setNum(bit);
}

void Widget::PrintText() {
    qDebug() << ui->lineEdit->text();
}
