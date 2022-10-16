#include <iostream>
using namespace std;

class Point
{
public:
    Point(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
        this->countP++;
    }
    Point(Point &p);

    int Geta()
    {
        return this->a;
    }
    int Getb()
    {
        return this->b;
    }
    void printf_p()
    {
        cout << "count_p=" << this->countP << endl;
    }

private:
    int a;
    int b;
    static int countP;
};

int Point::countP = 0;

Point::Point(Point &p)
{
    this->a = p.a;
    this->b = p.b;
    countP++;
}

int main()

{
    Point A(4, 5);
    cout << "Point A," << A.Geta() << "," << A.Getb();
    A.printf_p();
    Point B(A);
    cout << "Point B," << B.Geta() << "," << B.Getb();
    B.printf_p();
    return 0;
}