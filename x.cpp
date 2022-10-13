#include <iostream>
using namespace std;
/**
 * @brief namespace解决作用域不受限
 */

class Person
{
public:
    typedef enum
    {
        BOY = 0,
        GIRL
    } SexType;
};

namespace Color
{
    enum Type
    {
        RED = 15,
        YELLOW,
        BLUE
    };
};

/**
 * @brief 上述如果 using namespace Color 后，前缀还可以省去，使得代码简化。
 * 不过，因为命名空间是可以随后被扩充内容的，所以它提供的作用域封闭性不高。
 * 在大项目中，还是有可能不同人给不同的东西起同样的枚举类型名。
 * 更“有效”的办法是用一个类或结构体来限定其作用域。
 *
 * 定义新变量的方法和上面命名空间的相同。
 * 不过这样就不用担心类在别处被修改内容。
 * 这里用结构体而非类，一是因为本身希望这些常量可以公开访问，
 * 二是因为它只包含数据没有成员函数。
 */
struct Color1
{
    enum Type
    {
        RED = 102,
        YELLOW,
        BLUE
    };
};

/**
 * @brief C++11的枚举类
 * 下面等价于enum class Color2:int
 */
enum class Color2
{
    RED = 2,
    YELLOW,
    BLUE
};

enum class Color3 : char; // 前向声明

// 定义
enum class Color3 : char
{
    RED = 'r',
    BLUE
};

int main()
{
    int i = 4;
    int arr[5] = {0};
    int *ptr = arr;
    struct S
    {
        double d;
    } s;
    void Overloaded(int);
    void Overloaded(char); //重载的函数
    int &&RvalRef();
    const bool Func(int);

    //规则一：推导为其类型
    decltype(arr) var1; // int[] 标记符表达式

    decltype(ptr) var2; // int *  标记符表达式

    decltype(s.d) var3; // doubel 成员访问表达式

    // decltype(Overloaded) var4;//重载函数。编译错误。

    //规则二：将亡值。推导为类型的右值引用。

    decltype(RvalRef()) var5 = 1;

    //规则三：左值，推导为类型的引用。

    decltype((i)) var6 = i; // int&

    decltype(true ? i : i) var7 = i; // int&  条件表达式返回左值。

    decltype(++i) var8 = i; // int&  ++i返回i的左值。

    decltype(arr[5]) var9 = i; // int&. []操作返回左值

    decltype(*ptr) var10 = i; // int& *操作返回左值

    decltype("hello") var11 = "hello"; // const char(&)[9]  字符串字面常量为左值，且为const左值。

    //规则四：以上都不是，则推导为本类型

    decltype(1) var12; // const int

    decltype(Func(1)) var13 = true; // const bool

    decltype(i++) var14 = i; // int i++返回右值
    return 0;
}