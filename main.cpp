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
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QDebug>

QString GetStyleSheetContent() {
    QFile theme_config(":/resources/theme.conf");
    theme_config.open(QFile::ReadOnly);

    QString data = QString(theme_config.readAll()).remove("\n");

    QFile file(":/resources/" + data);
    bool result = file.open(QFile::ReadOnly);
    if (result) {
        QString content(file.readAll());
        file.close();
        theme_config.close();
        return content;
    } else {
        return "";
    }
}

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/resources/calculator.png"));
    a.setStyleSheet(GetStyleSheetContent());

    MainWindow w;
    w.resize(280, 410);
    w.setWindowTitle("calculator");
    w.move ((QApplication::desktop()->width() - w.width())/2,
            (QApplication::desktop()->height() - w.height())/2);
    w.show();

    return a.exec();
}
