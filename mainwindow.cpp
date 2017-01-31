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
#include "titlebar.h"
#include <QMouseEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    TitleBar *title = new TitleBar;
    title->setFixedHeight(36);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);

    this->setFocusPolicy(Qt::NoFocus);
    this->setMenuWidget(title);

    connect(title, SIGNAL(on_minimised()), this, SLOT(showMinimized()));
    connect(title, SIGNAL(on_closed()), this, SLOT(close()));
    connect(title, SIGNAL(on_closed()), this, SIGNAL(closed()));

    result->setEnabled(false);

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
    gridlayout->setSpacing(0);

    btn0->setFixedSize(70*2 ,55);
    btnIs->setFixedSize(70, 55*2);

    btnIs->setObjectName("TextButtonIs");
    btnClear->setStyleSheet("color: #2CA7F8;");

    widget->setLayout(gridlayout);
    this->setCentralWidget(widget);
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

void MainWindow::on_num_clicked(QString text)
{
    if (NumContinue == false) {
        label->clear();
        result->clear();
        result->insert(text);
        PointContinue = true;
    }else {
        result->insert(text);
    }

    NumContinue = true;
    SymbolContinue = true;
}

void MainWindow::on_symbol_clicked(QString text)
{
    QString get = result->text().replace("×", "*").replace("÷", "/");
    QString::const_iterator i = get.end();
    i--;

    if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
        result->backspace();
        result->insert(text);
    }

    if (SymbolContinue == false)
        return;

    if (result->text() == "") {
        result->insert("0");
    }

    result->insert(text);
    NumContinue = true;
    PointContinue = true;
    SymbolContinue = false;
}

void MainWindow::on_btnPoint_clicked()
{
    QString get = result->text().replace("×", "*").replace("÷", "/");
    QString::const_iterator i = get.end();
    i--;

    if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
        result->insert("0");
    }

    if (result->text() == "") {
        result->insert("0.");
        PointContinue = false;
    }

    if (*i == '.') {

    }

    if (PointContinue == true) {
        result->insert(".");
        PointContinue = false;
    }

    if (NumContinue == false) {
        label->clear();
        result->clear();
        result->insert("0.");
        NumContinue = true;
        SymbolContinue = false;
    }

    PointContinue = false;
    NumContinue = true;
}

void MainWindow::on_btnPlus_clicked()
{
    on_symbol_clicked("+");
}

void MainWindow::on_btnMinus_clicked()
{
    if (result->text() == "") {
        on_symbol_clicked("-");
        return;
    }
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

    PointContinue = true;
    NumContinue = true;
    SymbolContinue = true;
}

void MainWindow::on_btnBack_clicked()
{
    if (result->text() == "") return;

    QString text = result->text().replace("×", "*").replace("÷", "/");
    QString::const_iterator i = text.end();
    i--;

    if (*i == '0' || *i == '1' || *i == '2' || *i == '3' ||
        *i == '4' || *i == '5' || *i == '6' || *i == '7' ||
        *i == '8' || *i == '9') {
        result->backspace();
        NumContinue = true;
    }
    if (*i == '.'){
        result->backspace();
        PointContinue = true;
    }
    if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
        result->backspace();
        SymbolContinue = true;
        PointContinue = true;
    }

    i--;
    if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
        SymbolContinue = false;
    }
    if (*i == '.') {
        SymbolContinue = false;
    }

    NumContinue = true;
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

    NumContinue = false;  //input agin
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QRect rect = this->rect().marginsRemoved(QMargins(m_GlowRadius, m_GlowRadius, m_GlowRadius, m_GlowRadius));
    if (rect.contains(event->pos())) {
        if(event->button() == Qt::LeftButton) {
            m_MousePressed = true;
            m_LastMousePos = event->globalPos() - this->pos();
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if(m_MousePressed) {
        move(event->globalPos() - m_LastMousePos);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    m_MousePressed = false;
    event->accept();
}

