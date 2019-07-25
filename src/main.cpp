#include <iostream>
#include <stdlib.h>
#include "../include/Vector.h"
using namespace std;

int main()
{
    Vector v(6,8);
    cout<<v.magnitude()<<endl;
    cout<<v[1]<<endl;
    v[1]=9;
    cout<<v[1]<<endl;
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}}; 
    int n = sizeof(points)/sizeof(points[0]); 
    vector<Point> res=ConvexHull(points, n); 
    cout<<res.size()<<endl;
    return 0;
}