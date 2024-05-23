#include <cstring>

namespace ghb
{

template<typename T>

inline T *memcopy(T *dest, T const *src)
// Templated wrapper around memcpy.
//
// Return value is `dest` cast to `T *`, which is in accordance with the return
// value of `memcpy` being `dest` but as a `void *`
{
    return static_cast<T *>
    (
        std::memcpy
        (
            static_cast<void *>(dest),
            static_cast<void const *>(src),
            sizeof(T)
        )
    );
} 

}
