#include <QStack>
#include <QWidget>

#pragma once

class QLCDNumber;
class QPushButton;

class Calculator : public QWidget
{
    Q_OBJECT
private:
    QLCDNumber* plcd_;
    QStack<QString> stk_;
    QString strDisplay_;

public:
    Calculator(QWidget* pwgt = 0);
    QPushButton* createButtton(const QString& button);
    void calculate();

public slots:
    void slotButtonClicked();
};

