#include <iostream>
using namespace std;

class R
{
public:
    R(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void printf();
    void printf() const;

private:
    int a;
    int b;
};

void R::printf()
{
    cout << this->a << endl;
    cout << this->b << endl;
}

void R::printf() const
{
    cout << this->a << endl;
    cout << this->b << endl;
}

int main()
{
    R r1(1, 2);
    const R r2(3, 4);
    r1.printf();
    r2.printf();
    return 0;
}