#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QFile>

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);
    void initMenu();
    virtual void paintEvent(QPaintEvent *);
    void setStyle(const QString &style);


private:
    QLabel *m_title;

    QPushButton *menuButton;
    QPushButton *miniButton;
    QPushButton *closeButton;
    QMenu *m_menu;

signals:
    void on_minimised();
    void on_closed();
    void on_menued();
    void on_history();
};

#endif // TITLEBAR_H
