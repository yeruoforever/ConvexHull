#include <iostream>
#include <stdlib.h>
#include "../include/Vector.h"
using namespace std;

int main()
{
    Vector v(6,8);
    cout<<v.magnitude()<<endl;
    cout<<v[1]<<endl;
    v[1]=5;
    cout<<v[1]<<endl;
    system("pause");
    return 0;
}