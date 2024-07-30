#include <functional>
#include <optional>
#include <utility> // std::forward

namespace ghb
{

/*
 *
 * `make_optional` wraps a throwing function with return type `T` into a
 * noexcept function with return type `std::optional<T>`.
 *
 */ 

template<typename Rv, typename... Args>
std::function<std::optional<Rv> (Args...)> make_optional(std::function<Rv (Args...)> func) noexcept
{
    return [func](Args... args) noexcept -> std::optional<Rv>
    {
        try
        {
            return func(std::forward<Args>(args)...); 
        }
        catch(...)
        {
            return std::nullopt;
        }
    };
}

// Overload for function pointers.
template<typename Rv, typename... Args>
inline auto make_optional(Rv (*fptr)(Args...)) noexcept
{
    std::function<Rv (Args...)> func = fptr;
    return make_optional(func);
}

}

