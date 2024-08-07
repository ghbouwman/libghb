#ifndef CLASSNAME_HH
#define CLASSNAME_HH

#include <cstddef>
#include <utility>

#include "../../swap.tpp"

class CLASSNAME
{
    // All data members go inside this struct:
    struct D {
        

    } d;

    public:
        CLASSNAME() noexcept                                    = delete;
        CLASSNAME(CLASSNAME &&tmp) noexcept;
        CLASSNAME(CLASSNAME const &tmp) noexcept                = delete;

        CLASSNAME &operator=(CLASSNAME &&tmp) noexcept;
        CLASSNAME &operator=(CLASSNAME const &other) noexcept   = delete;
        
        // For move semantics:
        CLASSNAME clone() const noexcept;

        void swap(CLASSNAME &other) noexcept;
            
    private:
        // Auxiliary constructor for use with static member functions.
        explicit CLASSNAME(D data) noexcept;
};



CLASSNAME CLASSNAME::clone() const noexcept
{
    return CLASSNAME{d};
}



CLASSNAME::CLASSNAME(D data) noexcept
:   
    d(std::move(data))
{}



CLASSNAME::CLASSNAME(CLASSNAME &&tmp) noexcept
:
    d(std::move(tmp.d))
{}



void CLASSNAME::swap(CLASSNAME &other) noexcept
{
    ghb::swap(*this, other);
}



CLASSNAME &CLASSNAME::operator=(CLASSNAME &&tmp) noexcept
{
    swap(tmp);
    return *this;
}

#endif
