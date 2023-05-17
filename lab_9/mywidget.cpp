#include <QPainter>
#include "mywidget.h"
#include <figure.h>

//Губка-боб)

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    figures.push_back(new rectangular({300,500,500,100}));

    figures.push_back(new square({300,500,500,-1500}));

    figures.push_back(new circle({400, 100}, 100));
    figures.push_back(new circle({700, 100}, 100));

    figures.push_back(new circle({400, 100}, 40));
    figures.push_back(new circle({700, 100}, 40));

    figures.push_back(new elipse({550, 350}, 100, 50));

    figures.push_back(new triangle({500, 500}, {600, 500}, {550, 600}));
}

MyWidget::~MyWidget()
{
    for (auto& f: figures)
        delete f;
}
void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::black);

    for (const auto& f: figures)
    {
        f->draw(painter);
    }
}
