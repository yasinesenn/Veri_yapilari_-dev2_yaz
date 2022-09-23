/**
* @file ReadAndSort.cpp
* @description  Dosyadan satir satir okudugumuz sayilari arrayliste atar, sonrasinda bu sayilari kendi icerisinde siralar  
* @course Yaz Okulu 1-A
* @assignment 2. Odev
* @date 21.08.2022
* @author Yasin Emin Esen 
* B211210386 - yasin.esen2@ogr.sakarya.edu.tr
*/
#include "readAndSort.hpp"

readAndSort::readAndSort(string filename)
{
    
    this->filename = filename;
    int numlines = countLines();
    this->lines = new Arraylist *[numlines];
    for (int i = 0; i < numlines; i++)
    {
        this->lines[i] = new Arraylist();
    }
    readLine();
}

int readAndSort::countLines()
{
    int count = 0;
    ifstream file(this->filename);
    string lines;
    while (getline(file, lines))
        ++count;

    file.close();
    return count;
}

void readAndSort::readLine()
{
    string split;
    ifstream file(this->filename);
    string line;
    int index = 0;
    while (getline(file, split))
    {
        istringstream ss(split);

        while (getline(ss, line, ' '))
        {
            this->lines[index]->add(stoi(line));
        }
        index++;
    }

    file.close();
}

Arraylist **readAndSort::sortFile()
{

    int count = countLines();
    Radix radix;
    for (int i = 0; i < count; i++)
    {
        lines[i] = radix.radixsort(lines[i]);
    }

    return lines;
}

readAndSort::~readAndSort()
{
    if (lines != 0)
    {

        int count = countLines();
        for (int i = 0; i < count; i++)
        {

            if (lines[i] != 0)

                delete lines[i];
        }
        delete[] lines;
    }
}
