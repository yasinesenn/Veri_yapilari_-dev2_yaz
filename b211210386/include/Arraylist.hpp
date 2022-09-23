#ifndef Arraylist_hpp
#define Arraylist_hpp
#include <string.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
class Arraylist
{
public:
    Arraylist();
    Arraylist(int number);
    void add(int item);           // dizinin sonuna eleman ekler
    void insert(int i, int item); // dizin istelilen indisine eleman ekler
    int size() const;             // dizini boyutunu verir
    bool isEmpty() const;         // diziyi bos mu diye kontrol eder
    int elementAt(int i);         // belirtilen indisteki elemani verir
    void removeAt(int i);         // belirtilen indisteki elemani siler
    void clear();                 // diziyi sifirlar
    void putAt(int, int);         // dizinin istenilen yerine eleman koyar  insertten farki indisteki elemanin uzerine yaziliyor olmasi
    int first();                     // ilk elemani verir.
    int last();                      // son elemani verir.
    int lastIndex();                // son elemanin indexini verir.
    int sumArray(Arraylist*);
    ~Arraylist();
private:
    int *items;
    int length;
    int capacity;
    void reverse(int); // yeni alan olusturur
};

#endif