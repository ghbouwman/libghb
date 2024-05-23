#include "internal.ih"

NamedConstructor::NamedConstructor(NamedConstructor &&tmp) noexcept
:
    d(std::move(tmp.d))
{}

