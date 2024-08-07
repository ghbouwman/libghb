#include <iostream>
#include <stdexcept>
#include <string>

#include "make_optional.tpp"
#include "make_expected.tpp"
#include "big-num/big-num.hh"
#include "dropped/dropped.hh"

using namespace std;

class ZeroDivisionError : public exception
{
    string d_msg;

    public:
        explicit ZeroDivisionError(string const &s)
        : d_msg(s) {}

        char const *what() const noexcept override
        {
            return d_msg.c_str();
        }
};


double my_div(double top, double bottom)
{
    if (bottom == 0)
        throw(ZeroDivisionError("test"));

    return top / bottom;
}

/*
int main()
try
{
    // my_div(1, 0);
    
    auto better_div = ghb::make_expected(my_div);

    auto rv = better_div(1, 0);

    if (rv.has_value())
        cout << "this is not printed" << '\n';
    else
        cout << rv.error() << '\n';
}
catch(exception const &e)
{
    cout << e.what() << '\n';
}
*/

int main()
{
    string x{"test"};
    auto xp = &x;
    cout << ghb::drop(x) << '\n';
    cout << x << '\n';
    cout << xp << '\n';


}














