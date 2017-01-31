#include "historydialog.h"

HistoryDialog::HistoryDialog(QWidget * parent)
    : QDialog(parent)
{
    this->setFixedSize(400, 360);
    this->setWindowTitle("History");
    this->setAttribute(Qt::WA_DeleteOnClose);

    text->setFixedSize(400, 360);
    text->setFocusPolicy(Qt::NoFocus);

    this->setStyleSheet("background: #252525;");
    text->setStyleSheet("border: 0px; color: #CCCCCC; "
                        "background: #252525;"
                        "font-size: 20px; margin-top: 10px; margin-left: 10px; "
                        "padding-top: 5px;"
                        "padding-bottom: 5px;");
}
