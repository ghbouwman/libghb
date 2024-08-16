#include "big-num.ih"                          

/* Operator templating. 
 * 
 *
 *
 *
 *
 *
 *
 *
 */

#define OP_TPP(OP)                                          \
                                                            \
BigNum &BigNum::operator OP (BigNum const &other)           \
{                                                           \
    size_t size = max(d_nrs.size(), other.d_nrs.size());    \
    for (size_t index = 0; index != size; ++index)          \
        at(index) OP other.at(index);                       \
    return *this;                                           \
}                                                           \

OP_TPP(&=)
OP_TPP(|=)
OP_TPP(^=)

