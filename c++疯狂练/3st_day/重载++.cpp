#include <iostream>
using namespace std;

class R
{
public:
    R(int a, int b) : x(a), y(b) {}
    R operator++(int n)
    {
        R temp = *this;
        ++(*this);
        return temp;
    }
    R operator++()
    {
        this->x++;
        this->y++;
        return *this;
    }
    void printf()
    {
        cout<<x<<' '<<y<<endl;
    }

private:
    int x;
    int y;
};

int main()
{
    R r(1, 2);
    r.printf();
    (r++).printf();
    r.printf();
    (++r).printf();
    r.printf();

    return 0;
}