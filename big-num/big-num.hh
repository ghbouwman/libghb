#ifndef BIG_NUM_HH_346089
#define BIG_NUM_HH_346089

#include <vector>
#include <stdexcept>

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
        /*
        BigNum &operator >>=(BigNum const &other);
        BigNum &operator <<=(BigNum const &other);
        */

    private:
        size_t at(size_t index) const;
        size_t &at(size_t index);
        
        // void reduce_size();
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





#endif
