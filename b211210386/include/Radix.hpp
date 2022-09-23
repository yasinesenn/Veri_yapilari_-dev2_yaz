#ifndef Radix_HPP
#define Radix_HPP
#include "Arraylist.hpp"
#include <math.h>

class Radix
{

public:
    Radix();

    Arraylist *radixsort(Arraylist *); 
    ~Radix();

private:
    int max;
    int getMax(Arraylist *arr);
    void countSort(Arraylist *arr, int exp);
};

#endif