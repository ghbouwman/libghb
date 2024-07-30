#include <functional>
#include <expected>
#include <stdexcept>
#include <utility> // std::forward

namespace ghb
{

/*
 *
 * `make_expected` wraps a throwing function with return type `T` into a
 * noexcept function with return type `std::expected<T, ErrorT>`.
 *
 * Additionally, `ErrorT` and the type to catch on (ExceptionT) can
 * be specified and a `handle()` method can be specified to conversion.
 *
 */ 

template<typename ErrorT = std::string,
         typename ExceptionT = std::exception,
         typename Rv,
         typename... Args>
std::function<std::expected<Rv, ErrorT> (Args...)>
make_expected(std::function<Rv (Args...)> func,
              std::function<ErrorT (ExceptionT const &)> handle =
                  [](ExceptionT const &e) -> ErrorT
                  {
                      return ErrorT{e.what()};
                  }
             ) noexcept
{
    return [func, handle](Args... args) noexcept -> std::expected<Rv, ErrorT>
    {
        try
        {
            return func(std::forward<Args>(args)...); 
        }
        catch(ExceptionT const &obj)
        {
            return std::unexpected(handle(obj));
        }
    };
}

// Overload for function pointers.
template<typename Rv, typename... Args>
inline auto make_expected(Rv (*fptr)(Args...)) noexcept
{
    std::function<Rv (Args...)> func = fptr;
    return make_expected(func);
}

}

