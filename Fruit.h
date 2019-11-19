#include <QGraphicsRectItem>
#include <QTimer>

class Fruit : /*public QObject,*/ public QGraphicsRectItem
{
    //Q_OBJECT

public:
    Fruit();
    ~Fruit();

public slots:

    void Spawn();

private:
    //QTimer* timer;
    int RandomWidth() const;
    int RandomHeight() const;


};
