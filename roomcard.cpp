#include "roomcard.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

RoomCard::RoomCard(const QString &roomNumber, const QString &status, const QString &price, QWidget *parent)
    : QFrame(parent)
{
    setObjectName("cardKamar");
    setFixedSize(290, 150);

    QVBoxLayout *cardLayout = new QVBoxLayout(this);
    cardLayout->setContentsMargins(12, 12, 12, 12);

    QHBoxLayout *topLayout = new QHBoxLayout();
    lblRoom = new QLabel(roomNumber, this);
    lblRoom->setStyleSheet("font-weight: bold; font-size: 16px; color: #2c3e50;");

    lblStatus = new QLabel(status, this);
    setStatus(status);

    topLayout->addWidget(lblRoom);
    topLayout->addStretch();
    topLayout->addWidget(lblStatus);

    lblPrice = new QLabel(price, this);
    lblPrice->setStyleSheet("color: #7f8c8d; font-size: 13px;");

    btnDetail = new QPushButton("Detail", this);
    btnDetail->setStyleSheet("background-color: #3498db; color: white; border: none; border-radius: 4px; padding: 6px; font-size: 12px;");

    cardLayout->addLayout(topLayout);
    cardLayout->addWidget(lblPrice);
    cardLayout->addStretch();
    cardLayout->addWidget(btnDetail);
}

void RoomCard::setStatus(const QString &status) {
    lblStatus->setText(status);
    if (status == "Tersedia") {
        lblStatus->setStyleSheet("color: #27ae60; background-color: #e8f8f5; padding: 4px 8px; border-radius: 4px; font-size: 11px; font-weight: 600;");
    } else {
        lblStatus->setStyleSheet("color: #c0392b; background-color: #f5b7b1; padding: 4px 8px; border-radius: 4px; font-size: 11px; font-weight: 600;");
    }
}