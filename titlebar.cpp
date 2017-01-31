#include "titlebar.h"
#include <QPainter>
#include <QHBoxLayout>
#include <QApplication>
#include <QFile>
#include <QTextStream>

void TitleBar::setStyle(const QString &style)
{
    QFile qss(":/resources/" + style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}


TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    closeButton = new QPushButton(this);
    closeButton->setObjectName("CloseButton");
    closeButton->setFixedSize(27, 23);
    closeButton->setAttribute(Qt::WA_NoMousePropagation);
    closeButton->setFocusPolicy(Qt::NoFocus);
    connect(closeButton, SIGNAL(clicked()), this, SIGNAL(on_closed()));

    miniButton = new QPushButton(this);
    miniButton->setObjectName("MinimizeButton");
    miniButton->setFixedSize(27, 23);
    miniButton->setAttribute(Qt::WA_NoMousePropagation);
    miniButton->setFocusPolicy(Qt::NoFocus);
    connect(miniButton, SIGNAL(clicked()), this, SIGNAL(on_minimised()));

    menuButton = new QPushButton(this);
    menuButton->setObjectName("MenuButton");
    menuButton->setFixedSize(27, 23);
    menuButton->setAttribute(Qt::WA_NoMousePropagation);
    menuButton->setFocusPolicy(Qt::NoFocus);
    connect(menuButton, &QPushButton::clicked, this, [=] {
        if (parentWidget()) {
            const QPoint gp = this->mapToGlobal(QPoint(0, 0));
            const QSize ms = m_menu->sizeHint();
            const QPoint p(gp.x() + width() - ms.width() - 30,
            gp.y() + 36 - 10);
            m_menu->popup(p);
            menuButton->setVisible(false);
            menuButton->setVisible(true);
        }
    });

    m_title = new QLabel("Calculator");
    m_title->setStyleSheet("font-size: 14px; margin-bottom: 10px;");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(24, 0, 5, 0);
    layout->addWidget(m_title);
    layout->addStretch();

    layout->addWidget(menuButton);
    layout->addWidget(miniButton);
    layout->addWidget(closeButton);

    setLayout(layout);
    initMenu();
}

void TitleBar::initMenu()
{
    m_menu = new QMenu;

    QAction *white_mode = m_menu->addAction("Switch White Color");
    QAction *deep_mode = m_menu->addAction("Switch Deep Color");
    QAction *history = m_menu->addAction("History");
    QAction *aboutAction = m_menu->addAction("About");

    connect(m_menu, &QMenu::triggered, [this, aboutAction, history, white_mode, deep_mode](QAction *action)
    {
        if (history == action) {
            on_history();
        }else if (white_mode == action) {
            setStyle("light.qss");
        }else if (deep_mode == action) {
            setStyle("dark.qss");
        }
    });
}
void TitleBar::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect rect = this->rect();
    QPoint bottomLeft(rect.x(), rect.y() + rect.height());
    QPoint bottomRight(rect.x() + rect.width(), rect.y() + rect.height());

    QPen borderPen(QColor(0, 0, 0, 255*0.15));
    painter.setPen(borderPen);
    painter.drawLine(bottomLeft, bottomRight);
}
