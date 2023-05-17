#ifndef FIGURE_H
#define FIGURE_H

#include <QPoint>
#include <array>
#include <QPainter>
#include <QPolygon>
#include <vector>
#include <QVector>
#include <QRectF>

struct Figure
{
    virtual void draw(QPainter& painter) = 0;
    virtual ~Figure() {};
};

struct square : public Figure
{
    square(QRectF coord) : coord_(coord){};

    void draw(QPainter &painter) override {
        painter.setPen(Qt::yellow);
        painter.drawRect(coord_);
    }
    QRectF coord_;
    int width_;
    int height_;

};

struct rectangular : public Figure
{
    rectangular(QRectF coord) : coord_(coord){};

    void draw(QPainter &painter) override {
        painter.setPen(QColorConstants::Svg::brown);
        painter.drawRect(coord_);
    }
    QRectF coord_;
    int width_;
    int height_;

};

struct triangle : public Figure
{
    triangle(QPoint vert1, QPoint vert2, QPoint vert3) :  vert1_(vert1), vert2_(vert2), vert3_(vert3) {}

    void draw(QPainter &painter) override {
        painter.setPen(Qt::red);
        painter.drawPolygon(verts);
    }
    QPoint vert1_, vert2_, vert3_;
    QVector<QPoint> verts = {vert1_, vert2_, vert3_};

};

struct elipse : public Figure
{
    elipse(QPoint center, int radius1, int radius2) : center_(center), radius1_(radius1), radius2_(radius2)  {}

    void draw(QPainter &painter) override {
        painter.setPen(Qt::red);
        painter.drawEllipse(center_, radius1_, radius2_);
    }
    QPoint center_;
    int radius1_;
    int radius2_;
};

struct circle : public Figure
{
    circle(QPoint center, int radius1) : center_(center), radius1_(radius1) {}

    void draw(QPainter &painter) override {
        painter.setPen(Qt::black);
        painter.drawEllipse(center_, radius1_, radius1_);
    }
    QPoint center_;
    int radius1_;

};


#endif // FIGURE_H
