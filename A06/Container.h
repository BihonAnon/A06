#include <iostream>
#include "Sequence.h"

namespace CS52
{
    class Container : public Sequence
    {
    public:
        Container();                      // Default constructor
        Container(int size, int int_val); // Overloaded constructor
        Container(const Container &);     // Copy constructor
        ~Container();                     // Destructor
        // Returns a reference to the element at index i
        // throws a string if i is out-of-bounds.

        void info(const CS52::Container &c)
        {
            std::cout << "Testing" << std::endl;
        };

        int &at(int i) const throw(std ::string)
        {
            if (i < 0 || i >= _size)
                throw std ::string("Index out of bounds");
            return _data[i];
        };

        // Erases the elements of the Container but does not change capacity .
        void clear()
        {
            _size = 0;
        };
        int *data() const
        {
            // Returns pointer to the first element in the Container .
            return _data;
        };

        bool empty() const
        {
            // If Container is empty return true , else false .
            if (_size == 0)
                return true;
            else
                return false;
        };
        void pop_back()
        {
            _size--;
        };
        // Add an element to the end of the Container .
        void push_back(int element)
        {
            _data[_size] = element;
            _size++;
        };
        // Returns the number of elements in the Container .
        int size() const override
        {
            return _size;
        };
        // Returns the allocated storage for the Containter .
        int capacity() const override
        {
            return _capacity;
        };
        // Returns the type name ‘‘ Container ’’
        std::string type() const override
        {
            return "Container";
        };
        // Overloaded operators
        int &operator[](int index) // [] array syntax
        {
            return _data[index];
        };
        Container &operator=(const Container &) // copy assignment
        // overloaded + operator to add two Containers
        // m = [1 ,2 ,3] , n =[1 ,2 ,3]; o = m+n = [2 ,4 ,6]
        //
        // if rhs. size () < this - > size ()
        // return Container of rhs . size () ,
        // otherwise return Container this - size ();
        //
        {
            return *this;
        }
        Container operator+(const Container &rhs)
        {
            return *this;
        }
        // Overloaded stream insertion operator
        friend std ::ostream &operator<<(std ::ostream &, Container &)
        {
            return std::cout;
        };

    private:
        int _size = 0;
        int _capacity = 0;
        int *_data = nullptr;
    }; // Container
} // namespace
