#include <iostream>

/* 类，默认创建函数 */
class A
{
public:
    A() = default;
    ~A() = default;

    A(const A& a) = default;
    A(A&& a) = default;

    A& operator=(const A& a) = default;
    A& operator=(A&& a) = default;
};

/* 非成员运算符重载 */
std::ostream& operator<<(std::ostream& out, A a)
{
    return out;
}

std::istream& operator>>(std::istream& out, A a)
{
    return out;
}

/* 模版 */
template <typename T>
T func(T t)
{
    return t;
}

template <typename T>
class B
{
    T t;
};

/* 变量模版 */
template <typename T>
T a;


int main(void)
{
    A a;
    func(10);
    B<int> b;
    return 0;
}