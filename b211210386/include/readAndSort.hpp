#ifndef readAndSort_hpp
#define readAndSort_hpp
#include "Arraylist.hpp"
#include "Radix.hpp"
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

class readAndSort
{

public:
    readAndSort(string);
    Arraylist **sortFile();
    ~readAndSort();
    int countLines();

private:
    void readLine();
    Arraylist **lines;
    string filename;
};

#endif
