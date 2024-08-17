#ifndef GHB_MONAD_HH
#define GHB_MONAD_HH

template<typename T>
class Monad
{
    protected:
        Monad(T value);

        template <typename U>
        constexpr bind(std::function<Monad<U>(T)> const &func) -> Monad<U>; // make this variadic
}


#endif



Monad<T>
T -> Monad<T>
(Monad<T>, Fn(T) -> Monad<U>) -> Monad<U>
