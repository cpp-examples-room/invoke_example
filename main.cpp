#include <iostream>

class Foo {
public:
    void foo() { std::cout << __func__ << std::endl; }
};

template <typename T, typename Type, typename T1, typename... Args>
void invoke(Type T::* f, T1&& t1, Args&&... args) {
    (t1.*f)(args...);
}

int main() {
    invoke(&Foo::foo, Foo{});
}
