#include <cstddef>

#include "memcopy.tpp"

namespace ghb
{

template<typename T>
void swap(T &lhs, T &rhs) noexcept
{
    // We like to simply be able to enter the variables themselves,
    // but we need the pointers for the swapping.
    T *lhsPtr = &lhs;
    T *rhsPtr = &lhs;

    // no-op if trying to swap with itself.
    if (lhsPtr == rhsPtr)
        return;
    
    std::byte b[sizeof(T)];
    auto buffer = (T *) b; // N.B.: THIS IS A POINTER TO AN INVALID OBJECT!!!!

    ghb::memcopy(buffer, lhsPtr);
    ghb::memcopy(lhsPtr, rhsPtr);
    ghb::memcopy(rhsPtr, buffer);
}

}
