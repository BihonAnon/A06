/* Sequence class Declaration (A1) -- DONE*/
// Purpose : A container to hold an array of intergers (similar to std::vector<int>)
#ifndef SEQUENCE_H /*A1*/
#define SEQUENCE_H /*A1*/
#include <cassert> //for assert

namespace CS52
{
    class Sequence
    {
        private:
            int _size;
            int _capacity;
            int *_data;
        public:
            Sequence() = default;

            Sequence(int length):
                _size(length),
                _capacity(length),
                _data(new int[length])
            {
                assert(length >= 0);
                if (length >= 0)
                { 
                    _data = new int[length];
                }
            };
    }; // Class Sequence
}; // Namespace CS52
#endif /*A1*/