#ifndef GUARD_CLAUSE_BLAHBLAHBLAH
#define GUARD_CLAUSE_BLAHBLAHBLAH



class CLASSNAME : ABC
{
    struct D
    {
        // Private datamembers go here:





    } d; // Only instance of this object that should be instantiated.


    // No public data members are possible using this technique,
    // use getters and setters instead.


    public:
        // Public member functions go here:



        CLASSNAME &operator=(CLASSNAME &&other)
        {
            d = std::move(other.d);
            return *this;
        };


    private:
        // Private member functions go here:




        // Auxiliary function for use with static creator methods.
        explicit CLASSNAME(D data) : d(std::move(data)) {};
}


#endif
