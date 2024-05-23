#include <string>

class NamedConstructor
{
    // All data members go inside this struct:
    struct D {
        
        std::string str;
    
    } d;

    public:
        NamedConstructor(NamedConstructor &&tmp) noexcept;
        NamedConstructor &operator=(NamedConstructor &&tmp) noexcept;
        
        // Named "constructors".
        static NamedConstructor from_str(char const *str);
        static NamedConstructor from_prompt();
        

        // For move semantics:
        // NamedConstructor clone() { return };

        // For testing.
        void print() const;

    private:
        // Auxiliary constructor for use with static member functions.
        explicit NamedConstructor(D d) noexcept;
};

