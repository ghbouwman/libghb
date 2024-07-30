#include "make_optional_fn.tpp"
#include <iostream>

using namespace std;

double my_div(double top, double bottom)
{
    if (bottom == 0)
        throw("ZeroDivisionError");

    return top / bottom;
}

int main()
try
{
    cout << my_div(1, 2) << '\n';

    std::function<double (double, double)> better_div = ghb::make_optional_fn(my_div);
    cout << better_div(1, 0) << '\n';

    cout << my_div(1, 4) << '\n';
}
catch(...)
{
    cout << "Some exception was thrown." << '\n';
}
