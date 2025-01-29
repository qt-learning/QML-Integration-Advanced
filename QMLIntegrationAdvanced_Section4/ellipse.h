#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QPainter>
#include <QQmlEngine>
#include <QQuickPaintedItem>
#include <InterfaceShape.h>

class Ellipse : public InterfaceShape
{
    Q_OBJECT
    QML_ELEMENT
    QML_IMPLEMENTS_INTERFACES(InterfaceShape)
    Q_PROPERTY(float border READ border WRITE setBorder NOTIFY borderChanged FINAL)
    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged FINAL)

public:
    Ellipse();
    float border() const;
    void setBorder(float newBorder);
    void paint(QPainter *painter) override;
    Q_INVOKABLE void shapeInfo() override;
    Q_INVOKABLE void setProperties(float newBorder, QColor newColor);

public slots:
    void ellipseInfo();
    void onPropertyChanged();
    
signals:
    void colorChanged();
    void borderChanged();

private:
    QColor m_color;
    float m_border;
};

#endif // ELLIPSE_H
