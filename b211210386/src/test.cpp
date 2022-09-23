/**
* @file test.cpp
* @description Yazilar kodlarin testi ve istenilen programin calistirilmasi. 
* @course Yaz Okulu 1-A
* @assignment 2. Odev
* @date 21.08.2022
* @author Yasin Emin Esen 
* B211210386 - yasin.esen2@ogr.sakarya.edu.tr
*/
#include <cstdlib>
#include <iostream>
#include "Arraylist.hpp"
#include "Radix.hpp"
#include "readAndSort.hpp"
#include "AvlTree.hpp"

using namespace std;

int main(int argc, char **argv)
{

    Arraylist **Arraylist1;
    readAndSort *read = new readAndSort("Sayilar.txt");
    Arraylist1 = read->sortFile();
    AvlTree *avl = new AvlTree();

    for (int i = 0; i < read->countLines(); i++)
    {
        avl->Add(Arraylist1[i]);
    }
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "Preorder: " << endl;
    avl->preorder();

    delete Arraylist1;
    delete read;
    delete avl;
    return 0;
}