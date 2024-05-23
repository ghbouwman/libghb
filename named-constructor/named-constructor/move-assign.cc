#include "internal.ih"

NamedConstructor &NamedConstructor::operator=(NamedConstructor &&tmp) noexcept
{
    ghb::swap(*this, tmp);
    return *this;
}
