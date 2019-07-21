#include "Point.h"

class Edge
{
private:
    Point start;
    Point end;
public:
    Edge(Point theStart,Point theEnd);
    ~Edge();
    double distant();
};

Edge::Edge(Point theStart,Point theEnd)
{
}

Edge::~Edge()
{
}

double Edge::distant()
{
    return sqrt
}