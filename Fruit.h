#include <QGraphicsItem>

class Fruit : public QGraphicsItem
{
public:
    Fruit(qreal, qreal);

    QPainterPath shape() const;
    QRectF boundingRect() const; // Rectangle bouding the shape of food
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};
