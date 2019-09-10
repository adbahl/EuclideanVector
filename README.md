# EuclideanVector
Implementation of Euclidean Vector Class Library in C++

Interface given in EuclideanVector.h and its implementation in EuclideanVector.cpp.

Constructors
Constructor Description for Euclidean vectors to be defined in the following ways:

Constructor
A constructor that takes the number of dimensions (as an unsigned int) but
no magnitudes, sets the magnitude in each dimension as 0.0. Hint: you
may want to make this a delegating constructor to the next constructor
below.
This is the default constructor, with the default value being 1.
(1) EuclideanVector a(1);
(2) unsigned int i {3};
EuclideanVector b(i);
(3) EuclidenVector c; // or c{}
// same as EuclidenVector c(1);
Constructor: A constructor that takes the number of dimensions (as an unsigned int)
and initialises the magnitude in each dimension as the second argument (a
double)
(1) EuclideanVector a(2,4.0);
(2) unsigned int x {3};
double y {3.24};
EuclideanVector b(x,y);
Constructor: A constructor (or constructors) that takes the start and end of an iterator
and works out the required dimensions, and sets the magnitude in each
dimension according to the iterated values. The iterators will be from
std::vector or std::list. Hint: a function template may help. Hint 2: the
compiler prefers calling normal functions over templated functions, even
if it's an exact match for the template
(1) std::list l;
EuclideanVector
a{l.begin(),l.end()};
(2) std::vector v;
EuclideanVector
b{v.begin(),v.end()};
Constructor: An initialiser-list constructor that creates an Euclidean vector from a list
of double values. See Pages 220 -- 224 of the text. EuclideanVector a {1,2,3,4};
Constructor: A copy constructor EuclideanVector aCopy(a);
Constructor: A move constructor EuclideanVector aMove(a);

Running of Code:
Run the make file on linux machine
Run the code with following command
./EuclideanVectorTester
