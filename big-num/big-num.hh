#ifndef BIG_NUM_HH_346089
#define BIG_NUM_HH_346089

#include <vector>

class BigNum
{
    std::vector<size_t> d_nr;

    public:
        
        BigNum()
        : d_nr(){};

        BigNum(size_t nr)
        : d_nr(nr){};

        BigNum &operator &=(BigNum const &other);
        BigNum &operator |=(BigNum const &other);
        BigNum &operator ^=(BigNum const &other);
        BigNum &operator >>=(BigNum const &other);
        BigNum &operator <<=(BigNum const &other);
};







#endif
