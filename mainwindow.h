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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "algorithm.h"
#include "textbutton.h"
#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void initUI();
    void on_num_clicked(QString text);
    void on_symbol_clicked(QString text);

private:
    bool SymbolState = false;
    bool PointState = true; //cannot enter point
    bool PointState2 = false;
    bool NumState = true; //continue
    Algorithm *algorithm;

    QWidget *widget = new QWidget(this);
    QGridLayout *gridlayout = new QGridLayout;
    QLabel *label = new QLabel("");
    QLineEdit *result = new QLineEdit();

    TextButton *btnClear = new TextButton("C");
    TextButton *btnBack = new TextButton("←");
    TextButton *btnDiv = new TextButton("÷");
    TextButton *btn7 = new TextButton("7");
    TextButton *btn8 = new TextButton("8");
    TextButton *btn9 = new TextButton("9");
    TextButton *btnMult = new TextButton("×");
    TextButton *btn4 = new TextButton("4");
    TextButton *btn5 = new TextButton("5");
    TextButton *btn6 = new TextButton("6");
    TextButton *btnMinus = new TextButton("－");
    TextButton *btn1 = new TextButton("1");
    TextButton *btn2 = new TextButton("2");
    TextButton *btn3 = new TextButton("3");
    TextButton *btnPlus = new TextButton("＋");
    TextButton *btn0 = new TextButton("0");
    TextButton *btnPoint = new TextButton(".");
    TextButton *btnIs = new TextButton("＝");

private slots:
    void on_btn0_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
    void on_btnClear_clicked();
    void on_btnBack_clicked();
    void on_btnPoint_clicked();
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnMult_clicked();
    void on_btnDiv_clicked();
    void on_btnIs_clicked();
    void on_point_clicked();
};

#endif // MAINWINDOW_H
