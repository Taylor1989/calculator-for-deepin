#ifndef HISTORYDIALOG_H
#define HISTORYDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QTextEdit>

class HistoryDialog : public QDialog
{
public:
    explicit HistoryDialog(QWidget *parent = 0);
    QTextEdit *text = new QTextEdit(this);
};

#endif // HISTORYDIALOG_H
