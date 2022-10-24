#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    Point(int x = 0, int y = 0) 
     {
        this->x1 = x;
        this->y1 = y;
     }
    int get_x();
    int get_y();
    friend float distance(const Point &a, const Point &b);

private:
    int x1;
    int y1;
};

int Point::get_x()
{
    return this->x1;
}

int Point::get_y()
{
    return this->y1;
}

float distance(const Point &a, const Point &b)
{
    float dx = a.x1 - b.x1;
    float dy = a.y1 - b.y1;
    return sqrt(dx*dx - dy*dy);
}

int main()
{
    Point a(5,7);
    cout<<a.get_x()<<endl;
    Point b(8,9);
    cout<< distance(a,b)<<endl;
    return 0;
}