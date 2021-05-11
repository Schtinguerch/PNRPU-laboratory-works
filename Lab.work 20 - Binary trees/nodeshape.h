#ifndef NODESHAPE_H
#define NODESHAPE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>

class NodeShape: public QGraphicsItem
{
public:
    NodeShape();
    ~NodeShape();

    QColor NodeBrushColor = Qt::cyan;
    QColor NodePenColor = Qt::black;

    void SetNodeCoords(double& x, double& y);
    void SetTextCoords(double& x, double& y);
    void SetNodeRadius(double& radius);

protected:
    double node_x, node_y;
    double text_x, text_y;
    double node_radius;

    virtual QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
};

#endif // NODESHAPE_H
