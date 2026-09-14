#ifndef ROOMCARD_H
#define ROOMCARD_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>

class RoomCard : public QFrame {
    Q_OBJECT;
    public:
        explicit RoomCard(const QString &roomcard, const QString &status, const QString &price, QWidget *parent = nullptr);

        void setStatus(const QString &status);

    private:
        QLabel *lblRoom;
        QLabel *lblStatus;
        QLabel *lblPrice;
        QPushButton *btnDetail;

};

#endif // ROOMCARD_H
