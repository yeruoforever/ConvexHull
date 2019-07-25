#ifndef H_POINT

#include <cstring>
#include <iostream>
#include <vector>

#define MAX_DIMENSION 2

using namespace std;

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

#define CCW 1
#define CW -1
#define COLLINEAR 0

int orient_2d(const Point&a,const Point&b,const Point&c)
{
    double x1=b.coordinate[0]-a.coordinate[0];
    double x2=c.coordinate[0]-a.coordinate[0];
    double y1=b.coordinate[1]-a.coordinate[1];
    double y2=c.coordinate[1]-a.coordinate[1];
    double ans=x1*y2-x2*y1;
    return ans>0?CCW:ans==0?COLLINEAR:CW;
}

int orient(const Point&a,const Point&b,const Point&c)
{
    if(a.dimension==b.dimension&&a.dimension==c.dimension)
    {
        
        if(a.dimension==2)
        {
            return orient_2d(a,b,c);
        }
        else
        {
            throw std::exception("sorry,can not judge the orient in this dimension");
        }
        
    }
    else
    {
        throw std::exception("a,b,c must have the same dimension");
    }
}

vector<Point> ConvexHell(Point points[],int n)
{
    vector<Point> result;
    size_t mostLeftIndex=0;
    for(int i=1;i<n;i++)
    {
        if(points[i].coordinate[0]<points[mostLeftIndex].coordinate[0])
            mostLeftIndex=i;
    }
    int p=mostLeftIndex,q;
    do
    {
        result.push_back(points[p]);
        q=(p+1)%n;
        for(int i=0;i<n;i++)
        {
            if(orient_2d(points[p],points[i],points[q])==CCW)
            {
                q=i;
            }
        }
        p=q;
    }while(p!=mostLeftIndex);
}

#endif