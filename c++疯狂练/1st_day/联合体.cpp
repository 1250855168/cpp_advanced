#include <iostream>
using namespace std;

union x0
{
    struct
    {
        int x;
        int y;
        int z;
    } s;
    int k;
} u;

int main(int argc, char const *argv[])
{
    u.s.x = 1;
    u.s.y = 2;
    u.s.z = 3;

    printf("%d\n", u.s.x);
    printf("%d\n", u.s.y);
    printf("%d\n", u.s.z);

    u.k = 0;

    printf("%d\n", u.s.x);
    printf("%d\n", u.s.y);
    printf("%d\n", u.s.z);

    return 0;
}