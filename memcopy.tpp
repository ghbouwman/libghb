#include <cstring>

namespace ghb
{

template<typename T>

inline T *memcopy(T *dest, T const *src, size_t nr = 1)
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

}
