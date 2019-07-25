#ifndef H_VECTOR

#include "Point.h"

class Vector : public Point
{
private:
    /* data */
public:
    Vector();
    Vector(const Point& begin,const Point& end);
    template <typename... Args>
    Vector(Args... args);
    ~Vector();
    double magnitude();
    double operator*(const Vector& x);
};

Vector::Vector(const Point& begin,const Point& end)
{
    if(begin.dimension!=end.dimension)
    {
        throw std::exception("the dimension of start point and end point must be same");
    }
    else
    {
        dimension=begin.dimension;
        for(int i=0;i<dimension;i++)
        {
            coordinate[i]=end.coordinate[i]-begin.coordinate[i];
        }
    }
}


Vector::Vector()
{
}

template <typename... Args>
Vector::Vector(Args... args) : Point(args...)
{
}

Vector::~Vector()
{
}

double Vector::magnitude()
{
    double sum = 0.;
    for (int i = 0; i < dimension; i++)
    {
        sum += coordinate[i] * coordinate[i];
    }
    return sqrt(sum);
}

double Vector::operator*(const Vector&x)
{
    if(x.dimension!=dimension)
        throw std::exception("dismatch the dimension");
    double sum=0.;
    for(int i=0;i<dimension;i++)
    {
        sum+=coordinate[i]+x.coordinate[i];
    }
    return sum;
}

#endif
