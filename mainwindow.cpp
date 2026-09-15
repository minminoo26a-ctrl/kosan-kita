#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>
#include "roomcard.h"
#include <QScrollArea>
#include <QGridLayout>
#include <QVBoxLayout>

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


    /* Code Card */
    /* Code Card */
    QScrollArea *scrollArea = new QScrollArea(ui->stackedWidget->widget(0));
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);

    QWidget *container = new QWidget();
    container->setStyleSheet("background-color: transparent;");

    // Gunakan QVBoxLayout sebagai pembungkus utama di dalam container
    QVBoxLayout *mainContainerLayout = new QVBoxLayout(container);

    // (Opsional) Tambahkan Label Judul "Kamar Kos" di atas grid
    QLabel *lblTitle = new QLabel("Kamar Kos", container);
    lblTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #ffffff; margin-bottom: 10px;");
    mainContainerLayout->addWidget(lblTitle);

    // Grid layout untuk kartu-kartu
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSpacing(15);

    int row = 0;
    int col = 0;

    for (int i = 1; i <= 6; ++i) {
        QString roomName = "Kamar 10" + QString::number(i);
        QString status = (i % 2 == 0) ? "Terisi" : "Tersedia";
        QString price = "Rp 1.500.000 / bln";

        RoomCard *card = new RoomCard(roomName, status, price);

        gridLayout->addWidget(card, row, col);

        col++;
        if (col >= 4) {
            col = 0;
            row++;
        }
    }

    // Masukkan grid ke dalam layout vertikal utama container
    mainContainerLayout->addLayout(gridLayout);

    // INI KUNCINYA: Tambahkan stretch di bawah agar grid tidak merenggang ke bawah
    mainContainerLayout->addStretch();

    scrollArea->setWidget(container);

    QVBoxLayout *pageLayout = new QVBoxLayout(ui->stackedWidget->widget(0));
    pageLayout->setContentsMargins(0, 0, 0, 0); // Hilangkan margin agar pas
    pageLayout->addWidget(scrollArea);

}

MainWindow::~MainWindow()
{
    delete ui;
}
