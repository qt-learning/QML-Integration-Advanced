#ifndef FOREIGN_H
#define FOREIGN_H

#include <QtCore>
#include <QtQml>

#include <point2d.h>

struct Foreign
{
    Q_GADGET
    QML_FOREIGN(Point2D)
    QML_VALUE_TYPE(point2D)
};

#endif // FOREIGN_H
