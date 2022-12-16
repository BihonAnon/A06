/* Sequence class Declaration (A1) -- DONE*/
// Purpose : A container to hold an array of intergers (similar to std::vector<int>)
#ifndef SEQUENCE_H /*A1*/
#define SEQUENCE_H /*A1*/
#include <string>
namespace CS52
{
    class Sequence
    {
    public:
        virtual int size() const = 0;
        virtual int capacity() const = 0;
        virtual std ::string type() const = 0;
        virtual ~Sequence() {}
    };
}
#endif /*A1*/
