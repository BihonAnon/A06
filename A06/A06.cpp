// A06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Assignment Description
Build an integer Container class defined in namespace CS52 that has similar behavior to std::vector.
The Container will inherit from an abstract base class named Sequence. This assignment uses concepts
from Chapters 10,11,12,15 & 16. Topics include user defined types using classes, overloaded
operators, inheritance, virtual functions, and abstract classes.
The integer Container will have a default constructor, an overloaded constructor, a copy constructor,
and overloaded operators (i.e. bracket [], assignment =, stream insertion << and addition ’+’).
Use C++’s object oriented programming constructs like classes and resource management that relies on
constructors and destructors for memory management. Refer to the interface described on pages 2-3
of this handout for the Container class declaration. In A6, the implementations for Container and
Sequence will be separated into interface .h files Container.h and Sequence.h and implementation
.cpp files Container.cpp and A06.cpp, where A06.cpp is the driver/test program.
The Sequence base class has three pure virtual functions and a virtual destructor. The code in A6
is organized so that Container inherits from Sequence. Container will override the methods int
size(), int capacity() and std::string type() all declared as pure virtual functions in Sequence. Note
that type() will return the std::string “CS52::Container”. All of the classes will be declared in
namespace CS52. Refer to page 2 of this handout lists the Sequence and Container interfaces. Refer to
the driver code and output on pages 3-5 in this handout for an example of using the Container and
polymorphic behavior from using virtual functions.

*/
#include <iostream>

// Include the stuff from the other files, yay less errors.
#include "Sequence.h"
#include "Container.h"

int main()
{
    // default constructor , push_back , at methods
    std::cout << "// default constructor , push_back , at \n CS52 :: Container a;\n";
    CS52::Container a;
    std::cout << "\n a. push_back (10); a. push_back (88)\n";
    a.push_back(10);
    a.push_back(88);
    std ::cout << "a.at (0) = 99;\n";
    a.at(0) = 99;
    info(a);
    // b
    std ::cout << "\n// overloaded constructor , [] op , at , empty ,\
clear , exception handling : at \n CS52 :: Container b (2 ,5);\n";
    CS52 ::Container b(2, 5);
    std ::cout << "b is " << b << "\n";
    std ::cout << "\n// Add more elements to b\n";
    std ::cout << "b. push_back (10); b. push_back (2);\n";
    std ::cout << "b. push_back (99); b. push_back ( -5);\n";
    b.push_back(10);
    b.push_back(2);
    b.push_back(99);
    b.push_back(-5);
    std ::cout << "\n// array index [] and at ()\n";
    std ::cout << "b[0] = 25; b[1] = 1;\n";
    b[0] = 25;
    b[1] = 1;
    std ::cout << "b.at (0) ; b.at (1) ;\n";
    std ::cout << b.at(0) << " " << b.at(1) << "\n";
    std ::cout << "\n\n// empty method , size , and capacity \n";
    std ::cout << "b. empty () " << (b.empty() ? " True " : " False ") << "\n";
    std ::cout << "b. clear ()\n";
    b.clear();
    info(b);
    std ::cout << "b. empty () " << (b.empty() ? " True " : " False ") << "\n";
    std ::cout << "\n\n// Exception handling :";
    try
    {
        std ::cout << "\nb.at (9) = ";
        std ::cout << b.at(9);
    }
    catch (std ::string msg)
    {
        std ::cerr << "\n"
                   << msg << std ::endl;
    }
    // c
    std ::cout << "\n// copy constructor , copy assignment , pop_back ,\
\n// capacity , size \nCS52 :: Container c(b);\n";
    std ::cout << "\n// Add more elements to b\n";
    std ::cout << "b. push_back (11); b. push_back (7);\n";
    std ::cout << "b. push_back (3); b. push_back (23);\n";
    b.push_back(11);
    b.push_back(7);
    b.push_back(3);
    b.push_back(23);
    CS52 ::Container c(b);
    info(c);
    // d
    std ::cout << "\n// copy assignment \n";
    CS52 ::Container d;
    d = c;
    std ::cout << " CS52 :: Container d = c; "
               << "\n";
    std ::cout << "d is " << d << "\n";
    std ::cout << "\n// size vs capacity ()\n";
    std ::cout << "d. size () is " << d.size() << "\n";
    std ::cout << "d. capacity () is " << d.capacity() << "\n";
    std ::cout << "\n// pop_back ()\n";
    std ::cout << "d. pop_back ();d. pop_back ();\n";
    d.pop_back();
    d.pop_back();
    std ::cout << "\n// size vs capacity \n";
    std ::cout << "d. size () is " << d.size() << "\n";
    std ::cout << "d. capacity () is " << d.capacity() << "\n";
    // Test overloaded + operator
    CS52 ::Container m(5, 3);
    CS52 ::Container n(3, 0);
    n[0] = 55;
    n[1] = 100;
    n[2] = 500;
    CS52 ::Container o = m + n;
    std ::cout << " Test overloaded + operator \n";
    std ::cout << "m = [3 ,3 ,3 ,3 ,3] , n = [55 ,100 ,500]\n";
    std ::cout << "o = m + n = [" << o << "]\n";
    const int SIZE = 2;
    CS52 ::Sequence *sequence[SIZE];
    sequence[0] = new CS52 ::Container(2, 1);
    sequence[1] = new CS52 ::Container(5, 3);
    // Print out the type and length of each Sequence element
    std ::cout << "\nTest polymorphism \n";
    for (int i = 0; i < SIZE; i++)
    {
        std ::cout << " Sequence [" << i << "]"
                   << " is a " << sequence[i]->type()
                   << ": " << *(dynamic_cast<CS52 ::Container *>(sequence[i])) << "\n";
    }
    for (int i = 0; i < 2; i++)
        delete sequence[i];
    char stop;
    std ::cin >> stop;
    return 0;
} // main -- end of example driver code