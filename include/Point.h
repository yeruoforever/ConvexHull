#ifndef H_POINT

#include <cstring>
#include <iostream>

#define MAX_DIMENSION 2

class Point
{
protected:

    void unpick(double *array, double x);
    template <typename... Args>
    void unpick(double *array, double x, Args... args);

public:
    int dimension = MAX_DIMENSION;
    double coordinate[MAX_DIMENSION];

    Point();
    template <typename... Args>
    Point(Args... arg);
    ~Point();

    double& operator[](size_t pos);
};


/************************ 私有函数 *************************/
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



/************************* 构造函数 ************************/

Point::Point()
{
    memset(coordinate, 0, MAX_DIMENSION * sizeof(double));
}

template <typename... Args>
Point::Point(Args... args)
{
    Point();
    int len = sizeof...(args);
    if (len != MAX_DIMENSION)
        throw std::exception("Dimension error");
    else
    {
        unpick(coordinate, args...);
    }
}
/************************** 析构函数 ***********************/
Point::~Point()
{
}


/************************** 公有函数 ***********************/

double& Point::operator[](size_t pos) 
{
    if(pos<0||pos>=dimension)
        throw std::exception("Index Crossing Borders");
    return coordinate[pos];
}
#endif