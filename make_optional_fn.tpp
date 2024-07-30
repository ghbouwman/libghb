#include <functional>
#include <optional>

namespace ghb
{




template<typename Rv, typename ...Args>
std::function<std::optional<Rv> (Args...)> make_optional_fn(std::function<Rv (Args...)> func) noexcept
{
    std::remove_reference<...Args>
    return [&func](Args... args) noexcept
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

}
