#include "internal.ih"

NamedConstructor NamedConstructor::from_prompt()
{
    string str;
    cout << "Please enter contents of the object:" << '\n';
    cin >> str;
    cout << "Thank you!" << '\n';
    
    return NamedConstructor(D{
        str = str
    });
}
