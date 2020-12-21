#pragma once


#include <QGraphicsView>
#include <QPoint>


class Viewport: public QGraphicsView
{
    Q_OBJECT
public:
    Viewport(QWidget* parent = nullptr);
    explicit Viewport(QGraphicsScene* scene, QWidget* parent = nullptr);

    void mousePressEvent(QMouseEvent *event) override;

signals:
    void mouseClicked(const QPoint&);
};

