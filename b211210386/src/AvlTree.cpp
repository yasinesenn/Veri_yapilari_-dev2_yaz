/**
* @file AvlTree.cpp
* @description Avl agacina ekleme,cikarma, preorder siralama islemlerini yapar
* @course Yaz Okulu 1-A
* @assignment 2. Odev
* @date 21.08.2022
* @author Yasin Emin Esen 
* B211210386 - yasin.esen2@ogr.sakarya.edu.tr
*/
#include "AvlTree.hpp"

AvlTree::AvlTree()
{
    root = NULL;
}
Node *AvlTree::SearchAndAdd(Node *subNode, int item, Arraylist *items)
{
    if (subNode == NULL)
        subNode = new Node(items);
    else if (item < subNode->data)
    {
        subNode->left = SearchAndAdd(subNode->left, item, items);

        if (Height(subNode->left) == Height(subNode->right) + 2)
        {
            if (item < subNode->left->data)

                subNode = SwapWithLeftChild(subNode);
            else
            {

                subNode->left = SwapWithRightChild(subNode->left);
                subNode = SwapWithLeftChild(subNode);
            }
        }
    }
    else if (item > subNode->data)
    {
        subNode->right = SearchAndAdd(subNode->right, item, items);

        if (Height(subNode->right) == Height(subNode->left) + 2)
        {
            if (item > subNode->right->data)

                subNode = SwapWithRightChild(subNode);
            else
            {

                subNode->right = SwapWithLeftChild(subNode->right);
                subNode = SwapWithRightChild(subNode);
            }
        }
    }
    else
        ;

    subNode->height = Height(subNode);
    return subNode;
}

Node *AvlTree::SwapWithLeftChild(Node *subNode)
{
    Node *tmp = subNode->left;
    subNode->left = tmp->right;
    tmp->right = subNode;

    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->left), subNode->height);

    if (!subNode->line->isEmpty())
    {  
        cout << subNode->data << " nolu dugum asagi indigi icin en buyuk " << subNode->line->last() << " sayisi silinmistir" << endl;
        subNode->line->removeAt(subNode->line->lastIndex());
    }
    postorderDelMax(subNode->right);
    if (!tmp->line->isEmpty())
    {
        cout << tmp->data << " nolu dugum yukari ciktigi icin en kucuk " << tmp->line->elementAt(0) << " sayisi silinmistir" << endl;
        tmp->line->removeAt(0);
    }
    postorderDelMin(tmp->left);
    return tmp;
}
Node *AvlTree::SwapWithRightChild(Node *subNode)
{
    Node *tmp = subNode->right;
    subNode->right = tmp->left;
    tmp->left = subNode;

    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->right), subNode->height);
    if (!subNode->line->isEmpty())
    {
        cout << subNode->data << " nolu dugum asagi indigi icin en buyuk " << subNode->line->last() << " sayisi silinmistir" << endl;
        subNode->line->removeAt(subNode->line->lastIndex());
    }
    postorderDelMax(subNode->left);
    if (!tmp->line->isEmpty())
    {
        cout << tmp->data << " nolu dugum yukari ciktigi icin en kucuk " << tmp->line->first() << " sayisi silinmistir" << endl;
        tmp->line->removeAt(0);
    }
    postorderDelMin(tmp->right);
    return tmp;
}
bool AvlTree::DeleteNode(Node *&subNode)
{
    Node *delNode = subNode;

    if (subNode->right == NULL)
        subNode = subNode->left;
    else if (subNode->left == NULL)
        subNode = subNode->right;
    else
    {
        delNode = subNode->left;
        Node *parentNode = subNode;
        while (delNode->right != NULL)
        {
            parentNode = delNode;
            delNode = delNode->right;
        }
        subNode->data = delNode->data;
        if (parentNode == subNode)
            subNode->left = delNode->left;
        else
            parentNode->right = delNode->left;
    }
    delete delNode;
    return true;
}
void AvlTree::postorderDelMax(Node *subNode)
{
    if (subNode != NULL)
    {

        postorderDelMax(subNode->left);
        postorderDelMax(subNode->right);
        if (!subNode->line->isEmpty())
        {   
            cout << subNode->data << " nolu dugum asagi indigi icin en buyuk " << subNode->line->last() << " sayisi silinmistir" << endl;
            subNode->line->removeAt(subNode->line->lastIndex());
        }
    }
}
void AvlTree::postorderDelMin(Node *subNode)
{
    if (subNode != NULL)
    {

        postorderDelMin(subNode->left);
        postorderDelMin(subNode->right);
        if (!subNode->line->isEmpty())
        {
            cout << subNode->data << " nolu dugum yukari ciktigi icin en kucuk " << subNode->line->first() << " sayisi silinmistir" << endl;
            subNode->line->removeAt(0);
        }
    }
}
void AvlTree::preorder(Node *subNode)
{
    if (subNode != NULL)
    {
        cout << subNode->data << ": ";
        while (!subNode->line->isEmpty())
        {

            int number = subNode->line->first();
            std::cout << number << " ";
            subNode->line->removeAt(0);
        }
        cout << endl;
        preorder(subNode->left);
        preorder(subNode->right);
    }
}
int AvlTree::Height(Node *subNode)
{
    if (subNode == NULL)
        return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}

bool AvlTree::isEmpty() const
{
    return root == NULL;
}
void AvlTree::Add(Arraylist *item)
{
    int num = item->sumArray(item);
    root = SearchAndAdd(root, num, item);
}
void AvlTree::preorder()
{
    preorder(root);
}
int AvlTree::Height()
{
    return Height(root);
}
void AvlTree::Clear()
{
    while (!isEmpty())
        DeleteNode(root);
}
AvlTree::~AvlTree()
{
    Clear();
}