#ifndef GHB_PTR_HH
#define GHB_PTR_HH

template<typename T>
class Ptr
{
    T* d_ptr;
    
    public:
        Ptr();

        std::optional<T> operator*();

    private:
        
};

using namespace std;

template<typename T>
Ptr<T>::Ptr()
:
    d_ptr(nullptr)
{}

template<typename T>
optional<T> Ptr<T>::operator*()
{
    if (d_ptr == nullptr)
        return nullopt;
    return *d_ptr;
}

#endif
