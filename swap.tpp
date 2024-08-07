#include <cstddef>

#include "mem.tpp"

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
    
    std::byte b[sizeof(T)]; // Raw memory on the stack.
    
    // N.B.: After the C-style cast, `b` is of course not a valid `T` object.
    ghb::memcpy((T *)b, lhsPtr);
    ghb::memcpy(lhsPtr, rhsPtr);
    ghb::memcpy(rhsPtr, (T *)b);
}

}
