#include <cstring>

namespace ghb
{

template<typename T>
T *memcpy(T *dest, T const *src, size_t nr = 1) noexcept
// Templated wrapper around memcpy.
//
// Return value is `dest` cast to `T *`, which is in accordance with the return
// value of `memcpy` being `dest` but as a `void *`
//
// The `nr` argument is no longer the number of bytes, but rather the number of
// objects of type `T` sequentially in memory.
{
    return static_cast<T *>
    (
        std::memcpy
        (
            static_cast<void *>(dest),
            static_cast<void const *>(src),
            sizeof(T) * nr
        )
    );
} 

template<typename T>
T *memset(T *dest, std::byte ch, size_t nr = 1, bool force=true) noexcept
// Templated wrapper around memset(_explicit).
//
// Return value is `dest` cast to `T *`, which is in accordance with the return
// value of `memset` being `dest` but as a `void *`
//
// The `nr` argument is no longer the number of bytes, but rather the number of
// objects of type `T` sequentially in memory.
{
    auto fptr = &std::memset;
    /*
    auto fptr = &std::memset_explicit;

    if (!force) // allows the function to be optimised away
        fptr = &std::memset; // ordinary (potentially unsafe) memeset function.
    */

    return static_cast<T *>
    (
        (*fptr)
        (
            static_cast<void *>(dest),
            static_cast<int>(ch),
            sizeof(T) * nr
        )
    );
} 







} // namespace ghb
