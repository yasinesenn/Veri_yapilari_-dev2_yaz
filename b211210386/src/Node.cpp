/**
* @file Node.cpp
* @description Avl agacinde kullanilacak dugumlerin yapısının olusturulması 
* @course Yaz Okulu 1-A
* @assignment 2. Odev
* @date 21.08.2022
* @author Yasin Emin Esen 
* B211210386 - yasin.esen2@ogr.sakarya.edu.tr
*/
#include "Node.hpp"

Node::Node(Arraylist *arr, Node *lf, Node *rh)
{
    data = arr->sumArray(arr);
    line = arr;
    left = lf;
    right = rh;
    height = 0;
}

Node::Node(Arraylist *arr, Node *lf)
{
    data = arr->sumArray(arr);
    line = arr;
    left = lf;
    right = 0;
    height = 0;
}

Node::Node(Arraylist *arr)
{
    data = arr->sumArray(arr);
    line = arr;
    left = 0;
    right = 0;
    height = 0;
}