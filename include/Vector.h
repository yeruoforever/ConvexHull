#ifndef H_VECTOR

#include "./Point.h"

class Vector : public Point
{
private:
    /* data */
public:
    Vector();
    template <typename... Args>
    Vector(Args... args);
    ~Vector();
    double magnitude();
};

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

#endif
