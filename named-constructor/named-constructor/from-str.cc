#include "internal.ih"

NamedConstructor NamedConstructor::from_str(char const *str)
{
    size_t const len = strlen(str);

    cout << "The string \""
         << str 
         << "\" has a length of " 
         << len
         << '\n';

    
    return NamedConstructor(D{
        str = str
    });
    
}

