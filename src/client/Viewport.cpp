#include "Viewport.h"

#include <QMouseEvent>


Viewport::Viewport(QWidget* parent):
    QGraphicsView(parent)
{}

Viewport::Viewport(QGraphicsScene* scene, QWidget* parent):
    QGraphicsView(scene, parent)
{}

void Viewport::mousePressEvent(QMouseEvent* event)
{
    emit mouseClicked(event->pos());
}
