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

/***********************************************************/
#define OP_TPP(OP)                                          \
                                                            \
BigNum &BigNum::operator OP (BigNum const &other)           \
{                                                           \
    for (auto &&[lhs, rhs]: views::zip(d_nr, other.d_nr))   \
        lhs OP rhs;                                         \
    return *this;                                           \
}                                                           \
/***********************************************************/

OP_TPP(&=)
OP_TPP(|=)
OP_TPP(^=)
OP_TPP(>>=)
OP_TPP(<<=)
