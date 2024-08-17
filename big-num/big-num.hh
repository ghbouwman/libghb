#ifndef BIG_NUM_HH_346089
#define BIG_NUM_HH_346089

#include <vector>
#include <stdexcept>

namespace
{
    constexpr size_t SIZE_T_NR_BITS = 8 * sizeof(size_t)
}

class BigNum
{
    std::vector<size_t> d_nrs;

    public:
        
        BigNum()
        : d_nrs(){};

        BigNum(size_t nr)
        : d_nrs(nr){};

        BigNum &operator &=(BigNum const &other);
        BigNum &operator |=(BigNum const &other);
        BigNum &operator ^=(BigNum const &other);

        void small_shift_right();
        void small_shift_left();

        void big_shift_right();
        void big_shift_left();

        BigNum &operator >>=(size_t nr);
        BigNum &operator <<=(size_t nr);

    private:
        size_t at(size_t index) const;
        size_t &at(size_t index);
};

using namespace std;

size_t BigNum::at(size_t index) const
try
{
    return d_nrs.at(index);
}
catch (out_of_range const &e)
{
    return 0;
}

size_t &BigNum::at(size_t index) 
{
    d_nrs.resize(index + 1);
    return d_nrs.at(index);
}

void small_shift_right(size_t nr)
{
    // no-op
    if (nr == 0)
        return;

    size_t max_index = d_nrs.size() - 1; // Fails if d_nrs.size() == 0.
    
    size_t index = 0
    while (true)
    {   
        d_nrs[index] >>= nr;

        // final index does not have a carryover
        if (index == max_index)
            break;

        // carryover from next shift
        size_t carryover = d_nrs[index + 1] << (SIZE_T_NR_BITS - nr);
        d_nrs[index] += carryover;

        ++index;
    }

    // Reduce size.
    if (d_nrs[max_index] == 0)
        d_nrs.pop_back();
}

void small_shift_left(size_t nr)
{
    // no-op
    if (nr == 0)
        return;

    size_t max_index = d_nrs.size() - 1; // Fails if d_nrs.size() == 0.

    // Resize so we can savely copy (this is probably not the most efficient way).
    d_nrs.resize(d_nrs.size() + 1);

    size_t index = max_index;
    while (true)
    {   
        d_nrs[index] <<= nr; 

        // first index does not have a carryover
        if (index == 0)
            break;

        // carryover from next shift
        size_t carryover = d_nrs[index - 1] >> (SIZE_T_NR_BITS - nr);
        d_nrs[index] += carryover;

        --index;
    }

    // Reduce size.
    if (d_nrs[max_index] == 0)
        d_nrs.pop_back();
}

void big_shift_right(size_t nr)
{
    // no-op
    if (nr == 0)
        return;

    size_t size = d_nrs.size();

    for (size_t dest_index = 0; dest_index != size; ++dest_index)
    {   
        size_t src_index = dest_index + nr;

        // Branch will be reached `size - nr` amount of times.
        if (src_index < size)
            d_nrs[dest_index] = d_nrs[src_index];

        // Branch will be reached `nr` amount of times.
        else
            // We can delete the elements now they have all been copied.
            d_nrs.pop_back();
    }
}

void big_shift_left(size_t nr);
{
    // no-op
    if (nr == 0)
        return;
    
    // Resize so we can savely copy (this is probably not the most efficient way).
    d_nrs.resize(d_nrs.size() + nr);

    for (size_t dest_index = d_nrs.size(); dest_index--; /* empty */)
    {   

        // Branch will be reached `size - nr` amount of times.
        if (dest_index >= nr)
        {
            // we do this inside the if statement to mitigate underflow.
            src_index = dest_index - nr; 

            d_nrs[index] = d_nrs[fetch];
        }

        // Branch will be reached `nr` amount of times.
        else
            // Shifted elements will simply be zero.
            d_nrs[index] = 0;
    }
}

BigNum &operator >>=(size_t nr)
{
    if (d_nrs.size() == 0) // necessary for the "small shift" implementations.
        return *this; 
    
    size_t nr_elements = nr / SIZE_T_NR_BITS
    if (nr_elements != 0) 
        big_shift_right(nr_elements);

    size_t nr_bits = nr % SIZE_T_NR_BITS
    if (nr_bits != 0) 
        small_shift_right(nr_bits);

    d_nrs.shrink_to_fit();
    return *this;
}

BigNum &operator <<=(size_t nr)
{
    if (d_nrs.size() == 0) // necessary for the "small shift" implementations.
        return *this; 
    
    size_t nr_elements = nr / SIZE_T_NR_BITS
    if (nr_elements != 0) 
        big_shift_left(nr_elements);

    size_t nr_bits = nr % SIZE_T_NR_BITS
    if (nr_bits != 0) 
        small_shift_left(nr_bits);

    d_nrs.shrink_to_fit();
    return *this;
}

#endif
