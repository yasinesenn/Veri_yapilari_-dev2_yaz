#ifndef AvlTree_HPP
#define AvlTree_HPP
#include <iostream>
#include <cmath>
#include "Node.hpp"
#include "Arraylist.hpp"
using namespace std;

class AvlTree {
private:
    Node *root;
    Node* SearchAndAdd(Node *subNode, int item, Arraylist *items);
    Node* SwapWithLeftChild(Node *subNode);
    Node* SwapWithRightChild(Node *subNode);
    bool DeleteNode(Node *&subNode);
    void postorderDelMax(Node *subNode);
    void postorderDelMin(Node *subNode);
    void preorder(Node *subNode);
    int Height(Node *subNode);

public:
    AvlTree();
    bool isEmpty()const;
    void Add(Arraylist* item);
    void preorder();
    int Height();
    void Clear();
    ~AvlTree();
};


#endif 