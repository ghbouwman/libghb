

template<typename T>
class Late<T>
{


public:
    Late();

    template<typename... Args>
    void init(Args &&args);


}

template<typename T>
Late<T>::Late()
    : d_buf
{
}



template<typename... Args>
inline void init(Args &&args)
{
    T{ std::forward(args) };
}
