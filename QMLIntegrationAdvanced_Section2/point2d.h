#ifndef POINT2D_H
#define POINT2D_H

#include <QtCore>
#include <QtQml>

class Point2D
{
    Q_GADGET
    QML_VALUE_TYPE(point2D)
    Q_PROPERTY(float coordinate1 READ coordinate1 WRITE setCoordinate1 FINAL)
    Q_PROPERTY(float coordinate2 READ coordinate2 WRITE setCoordinate2 FINAL)

public:
    enum CoordinateSystem { Cartesian = 0, Polar };
    Q_ENUM(CoordinateSystem)

    Point2D(float coord1 = 0.0,
            float coord2 = 0.0,
            CoordinateSystem system = CoordinateSystem::Cartesian);
    Q_INVOKABLE QString positionInfo(CoordinateSystem system = CoordinateSystem::Cartesian);
    float coordinate1() const;
    void setCoordinate1(float newCoordinate1);
    float coordinate2() const;
    void setCoordinate2(float newCoordinate2);

private:
    float m_coordinate1;
    float m_coordinate2;
};

#endif // POINT2D_H
