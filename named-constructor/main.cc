#include "main.ih"

int main()
{
    char const str[] = "Hello, world!";
    auto obj1 = NamedConstructor::from_str(str);
    auto obj2 = move(obj1);
    obj1.print();
    obj2.print();
    auto obj3 = NamedConstructor::from_prompt();
}
