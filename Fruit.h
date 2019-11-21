#include <QGraphicsItem>

class Fruit : public QGraphicsItem
{
public:
    Fruit(qreal, qreal);

    //std::string name() const { return "Fruit"; }

    QPainterPath shape() const;
    QRectF boundingRect() const; // Rectangle bouding the shape of food
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};
