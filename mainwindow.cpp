/*
* Copyright (C) 2017 rekols@foxmail.com(Juns Steven)

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    result->setFocusPolicy(Qt::NoFocus);

    initUI();

    connect(btn0, SIGNAL(clicked()), this, SLOT(on_btn0_clicked()));
    connect(btn1, SIGNAL(clicked()), this, SLOT(on_btn1_clicked()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(on_btn2_clicked()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(on_btn3_clicked()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(on_btn4_clicked()));
    connect(btn5, SIGNAL(clicked()), this, SLOT(on_btn5_clicked()));
    connect(btn6, SIGNAL(clicked()), this, SLOT(on_btn6_clicked()));
    connect(btn7, SIGNAL(clicked()), this, SLOT(on_btn7_clicked()));
    connect(btn8, SIGNAL(clicked()), this, SLOT(on_btn8_clicked()));
    connect(btn9, SIGNAL(clicked()), this, SLOT(on_btn9_clicked()));
    connect(btnPoint, SIGNAL(clicked()), this, SLOT(on_btnPoint_clicked()));
    connect(btnClear, SIGNAL(clicked()), this, SLOT(on_btnClear_clicked()));
    connect(btnBack, SIGNAL(clicked()), this, SLOT(on_btnBack_clicked()));
    connect(btnPlus, SIGNAL(clicked()), this, SLOT(on_btnPlus_clicked()));
    connect(btnMinus, SIGNAL(clicked()), this, SLOT(on_btnMinus_clicked()));
    connect(btnMult, SIGNAL(clicked()), this, SLOT(on_btnMult_clicked()));
    connect(btnDiv, SIGNAL(clicked()), this, SLOT(on_btnDiv_clicked()));
    connect(btnIs, SIGNAL(clicked()), this, SLOT(on_btnIs_clicked()));
}

void MainWindow::initUI()
{
    btnIs->setFocus();
    btnIs->setShortcut(QKeySequence::InsertParagraphSeparator);

    label->setMargin(10);
    label->setAlignment(Qt::AlignRight);
    result->setAlignment(Qt::AlignRight);

    gridlayout->addWidget(label, 0, 0, 1, 4);
    gridlayout->addWidget(result, 1, 0, 1, 4);
    gridlayout->addWidget(btnClear, 2, 0);
    gridlayout->addWidget(btnBack, 2, 1);
    gridlayout->addWidget(btnDiv, 2, 2);
    gridlayout->addWidget(btnMult, 2, 3);
    gridlayout->addWidget(btn7, 3, 0);
    gridlayout->addWidget(btn8, 3, 1);
    gridlayout->addWidget(btn9, 3, 2);
    gridlayout->addWidget(btnMinus, 3, 3);
    gridlayout->addWidget(btn4, 4, 0);
    gridlayout->addWidget(btn5, 4, 1);
    gridlayout->addWidget(btn6, 4, 2);
    gridlayout->addWidget(btnPlus, 4, 3);
    gridlayout->addWidget(btn1, 5, 0);
    gridlayout->addWidget(btn2, 5, 1);
    gridlayout->addWidget(btn3, 5, 2);
    gridlayout->addWidget(btn0, 6, 0, 1, 2);
    gridlayout->addWidget(btnPoint, 6, 2);
    gridlayout->addWidget(btnIs, 5, 3, 2, 2);

    gridlayout->setMargin(0);
    gridlayout->setSpacing(2);

    btn0->setFixedSize(70*2 ,55);
    btnIs->setFixedSize(70, 55*2);

    btnIs->setObjectName("TextButtonIs");
    btnClear->setStyleSheet("color: #2CA7F8; outline: none;");

    widget->setLayout(gridlayout);
    this->setCentralWidget(widget);
}

void MainWindow::on_point_clicked()
{
    if (PointState == true) {
        if (NumState == false) {
            label->clear();
            result->clear();
            result->insert("0");
        }
        if (result->text() == "") {
            result->insert("0");
        }
        if (PointState2 == true) {
            result->insert("0");
        }

        result->insert(".");
        PointState = false;
        NumState = true;
        SymbolState = false;
    }else {
        if (NumState == false) {
            label->clear();
            result->clear();
            result->insert("0.");
        }
    }
}

void MainWindow::on_num_clicked(QString text)
{
    PointState2 = false;

    if (NumState == false) {
        label->clear();
        result->clear();
        result->insert(text);
    }else {
        result->insert(text);
    }

    NumState = true;
    SymbolState = true;
}

void MainWindow::on_symbol_clicked(QString text)
{
    NumState = true;
    PointState = true;
    PointState2 = true;

    if (SymbolState == true) {
        result->insert(text);
        SymbolState = false;
    }else {
        if (result->text() == "") {
            if (text == "-") {
                result->insert("-");
            }else {
                result->insert("0" + text);
            }
        }
    }

    
}

void MainWindow::on_btn0_clicked()
{
    on_num_clicked("0");
}

void MainWindow::on_btn1_clicked()
{
    on_num_clicked("1");
}

void MainWindow::on_btn2_clicked()
{
    on_num_clicked("2");
}

void MainWindow::on_btn3_clicked()
{
    on_num_clicked("3");
}

void MainWindow::on_btn4_clicked()
{
    on_num_clicked("4");
}

void MainWindow::on_btn5_clicked()
{
    on_num_clicked("5");
}

void MainWindow::on_btn6_clicked()
{
    on_num_clicked("6");
}

void MainWindow::on_btn7_clicked()
{
    on_num_clicked("7");
}

void MainWindow::on_btn8_clicked()
{
    on_num_clicked("8");
}

void MainWindow::on_btn9_clicked()
{
    on_num_clicked("9");
}

void MainWindow::on_btnPoint_clicked()
{
    on_point_clicked();
}

void MainWindow::on_btnPlus_clicked()
{
    on_symbol_clicked("+");
}

void MainWindow::on_btnMinus_clicked()
{
    on_symbol_clicked("-");
}

void MainWindow::on_btnMult_clicked()
{
    on_symbol_clicked("×");
}

void MainWindow::on_btnDiv_clicked()
{
    on_symbol_clicked("÷");
}

void MainWindow::on_btnClear_clicked()
{
    result->clear();
    label->clear();

    SymbolState = false;
    NumState = true;
    PointState = true;
    PointState2 = false;
}

void MainWindow::on_btnBack_clicked()
{
    if (result->text() == "") return;

    QString get = result->text().replace("×", "*").replace("÷", "/");
    QString::const_iterator i = get.end();
    i--;

    if (*i == '0' || *i == '1' || *i == '2' || *i == '3' || *i == '4' ||
        *i == '5' || *i == '6' || *i == '7' || *i == '8' || *i == '9') {
        if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
            SymbolState = false;
        }
        result->backspace();
        NumState = true;
    }
    if (*i == '.') {
        result->backspace();
        PointState = true;
        PointState2 = false;
    }
    if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
        result->backspace();
        SymbolState = true;
    }

    i--;
    if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
        SymbolState = false;
    }
    if (*i == '.') {
        SymbolState = false;
    }
}

void MainWindow::on_btnIs_clicked()
{
    if(result->text() == "") {
        return;
    }

    label->setText(result->text());

    QString expression = label->text().replace("×", "*").replace("÷", "/");
    double get_result = algorithm->expressionCalculate(expression.toStdString());
    QString data = QString::number(get_result);

    result->setText(data);
    label->setToolTip(label->text());

    NumState = false;  //input agin
}

