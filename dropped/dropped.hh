#ifndef GHB_DROPPED_HH
#define GHB_DROPPED_HH

#include <utility> // std::move
#include "../mem.tpp" // contains ghb::memset

namespace ghb
{


template<typename T>
class Dropped : public T
{
    T *d_ptr;

    public:
        constexpr Dropped(T *ptr) noexcept;
        constexpr ~Dropped() noexcept;
        constexpr operator T() noexcept;

    private:
        template<typename U> // different letter needed for friend declaration.
        friend constexpr Dropped<U> drop(U const &obj) noexcept;
};

template<typename T>
constexpr Dropped<T>::Dropped(T *ptr) noexcept
:
    d_ptr(ptr)
{}

template<typename T>
constexpr Dropped<T>::operator T() noexcept
{
    return *d_ptr;
}

template<typename T>
constexpr Dropped<T>::~Dropped() noexcept
{
    d_ptr->T::~T();
    ghb::memset(d_ptr, 0);
}

template<typename T>
constexpr Dropped<T> drop(T &obj) noexcept
{
    return Dropped(&obj);
}


} // namespace ghb

#endif
