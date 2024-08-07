template <typename T>
typename remove_reference<T>::type&& move(T&& arg) noexcept
{
    return static_cast<remove_reference<T>::type&&>(arg);
}
