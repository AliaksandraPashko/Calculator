#include "calculator.h"

#include <QGridLayout>
#include <QLCDNumber>

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

