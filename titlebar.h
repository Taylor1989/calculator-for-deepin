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
    void minimised();
    void closed();
};

#endif // TITLEBAR_H
