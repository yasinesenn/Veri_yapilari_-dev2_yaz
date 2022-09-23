/**
* @file Radix.cpp
* @description Gelen arraylisti radix sort ile buyukten kucuge siralar.
* @course Yaz Okulu 1-A
* @assignment 2. Odev
* @date 21.08.2022
* @author Yasin Emin Esen 
* B211210386 - yasin.esen2@ogr.sakarya.edu.tr
*/
#include "Radix.hpp"
#include "math.h"
using namespace std;

Radix::Radix()
{

    max = 0;
}
Radix::~Radix(){}

int Radix::getMax(Arraylist *arr)
{
    max = arr->elementAt(0);
    for (int i = 1; i < arr->size(); i++)
        if (arr->elementAt(i) > max)
            max = arr->elementAt(i);
    return max;
}
void Radix::countSort(Arraylist *arr, int exp)
{
    int output[arr->size()]; 
    int i, count[10] = {0};

   
    for (i = 0; i < arr->size(); i++)
        count[(arr->elementAt(i) / exp) % 10]++;

    
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for (i = arr->size() - 1; i >= 0; i--)
    {
        output[count[(arr->elementAt(i) / exp) % 10] - 1] = arr->elementAt(i);
        count[(arr->elementAt(i) / exp) % 10]--;
    }

  
    for (i = 0; i < arr->size(); i++)
        arr->putAt(i, output[i]);
}
Arraylist *Radix::radixsort(Arraylist *arr)
{

     max = getMax(arr);
  
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, exp);
    }
   
    return arr;
}
