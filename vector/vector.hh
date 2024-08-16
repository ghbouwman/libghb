#ifndef GHB_VECTOR_HH
#define GHB_VECTOR_HH

#include <vector>
using namespace std;


namespace ghb
{

template<typename T>
class Vector : std::vector<T>
{
    std::optional<T const &> operator[](size_t index) const = ghb::make_optional(at);
    std::optional<T &> operator[](size_t index) = ghb::make_optional(at);

    T const &at(size_t index) const = delete;
    T &at(size_t index) = delete;
};





} // namespace ghb

#endif
