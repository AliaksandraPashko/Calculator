#include "calculator.h"

#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>

Calculator::Calculator (QWidget* pwgt) : QWidget(pwgt)
{
    plcd_ = new QLCDNumber(12);
    plcd_->setSegmentStyle(QLCDNumber::Flat);
    plcd_->setMinimumSize(150, 50);

    QChar aButtons[4][4] = { { '7', '8', '9', '/' },
                             { '4', '5', '6', '*' },
                             { '1', '2', '3', '-' },
                             { '0', '.', '=', '+' }
                           };

    QGridLayout* pLayout = new QGridLayout;
    pLayout->addWidget(plcd_, 0, 0, 1, 4);
    pLayout->addWidget(createButton("CE"), 1, 3);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j )
        {
            pLayout->addWidget(createButton(aButtons[i][j]), i+2, j);
        }
    }
    setLayout(pLayout);
}

QPushButton* Calculator :: createButton(const QString& buttonName)
{
    QPushButton* button = new QPushButton(buttonName);
    button->setMinimumSize(40,40);
    connect(button, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return button;
}

void Calculator :: calculate()
{
    double strOperand2 = stk_.pop().toDouble();
    QString strOperation = stk_.pop();
    double strOperand1 = stk_.pop().toDouble();

    double result = 0;

    if (strOperation == "+")
        result = strOperand1 + strOperand2;

    if (strOperation == "-")
        result = strOperand1 - strOperand2;

    if (strOperation == "*")
        result = strOperand1 * strOperand2;

    if (strOperation == "/")
        result = strOperand1 / strOperand2;

    plcd_->display(result);
}
