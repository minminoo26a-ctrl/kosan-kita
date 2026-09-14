#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(1024, 768);
    this->setWindowTitle("KosanKita");

    ui->btnKamar->setIcon(QIcon(":/Icon/icon/kamar.png"));
    ui->btnKamar->setIconSize(QSize(16, 16));

    ui->btnPenghuni->setIcon(QIcon(":/Icon/icon/user.png"));
    ui->btnPenghuni->setIconSize(QSize(16, 16));

    ui->btnKeuangan->setIcon(QIcon(":/Icon/icon/keuangan.png"));
    ui->btnKeuangan->setIconSize(QSize(16, 16));

    connect(ui->btnKamar, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });


    connect(ui->btnPenghuni, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->btnKeuangan, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
