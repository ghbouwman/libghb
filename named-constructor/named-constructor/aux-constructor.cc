#include "internal.ih"

NamedConstructor::NamedConstructor(D data) noexcept
:
    d(std::move(data))
{
    cout << "Object is now initialised with string: \""
         << d.str
         << '\"'
         << '\n';
}

