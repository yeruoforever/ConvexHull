#ifndef H_POINT

#include <cstring>
#include <iostream>

#define DIMENSION 2

class Point
{
protected:
    double coordinate[DIMENSION];
    void unpick(double *array, double x);
    template <typename... Args>
    void unpick(double *array, double x, Args... args);

public:
    int dimension = DIMENSION;
    Point();
    template <typename... Args>
    Point(Args... arg);
    ~Point();
};

Point::Point()
{
    memset(coordinate, 0, DIMENSION * sizeof(double));
}

void Point::unpick(double *array, double x)
{
    *array = x;
}

template <typename... Args>
void Point::unpick(double *array, double x, Args... args)
{
    *array = x;
    unpick(++array, args...);
}
template <typename... Args>
Point::Point(Args... args)
{
    Point();
    int len = sizeof...(args);
    if (len != DIMENSION)
        throw std::exception("Dimension error");
    else
    {
        unpick(coordinate, args...);
    }
}

Point::~Point()
{
}

#endif