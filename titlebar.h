#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent *);


private:
    QLabel *m_title;

    QPushButton *menuButton;
    QPushButton *miniButton;
    QPushButton *closeButton;

signals:
    void on_minimised();
    void on_closed();
};

#endif // TITLEBAR_H
