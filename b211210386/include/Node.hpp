#ifndef Node_HPP
#define Node_HPP
#include "Arraylist.hpp"

class Node {
public:
    int data;
    Arraylist* line;
    Node *left;
    Node *right;
    int height;

    Node(Arraylist* arr, Node *lf, Node *rh);
    Node(Arraylist* arr, Node *lf);
    Node(Arraylist* arr);
};


#endif 