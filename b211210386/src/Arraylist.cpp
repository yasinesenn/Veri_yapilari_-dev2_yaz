/**
* @file Arraylist.cpp
* @description Arralistte gerekli islemleri yapabilmemizi saglayan fonskiyonlar 
* @course Yaz Okulu 1-A
* @assignment 2. Odev
* @date 21.08.2022
* @author Yasin Emin Esen 
* B211210386 - yasin.esen2@ogr.sakarya.edu.tr
*/

#include "Arraylist.hpp"

using namespace std;

Arraylist::Arraylist()
{
    length = 0;
    capacity = 0;
    items = 0;
}
Arraylist::Arraylist(int number)
{
    Arraylist();
    for (int i = 0; i < number; i++)
    {
        this->add(number);
    }
}
void Arraylist::reverse(int newCapacity)
{
    if (capacity >= newCapacity)
        return;                      // yeni kapasite eskisinden kucukse hicbirsey yapmaz
    int *tmp = new int[newCapacity]; // tmp degiskenine daha buyuk kapasiteli dizi olusturulur
    for (int i = 0; i < length; i++)
    { // items 'in icindeki veri tmp dizisine kopyalanir
        tmp[i] = items[i];
    }
    if (items != 0)
    { // items dizisi degil ise silinir heap bellekte cop olusmamasi icin
        delete[] items;
    }
    items = tmp;            // gecici dizinin adresi items degikenine atanir
    capacity = newCapacity; // kapasite bilgisi yenilenir
}
void Arraylist::add(int item)
{
    insert(length, item);
} // dizinin sonuna eleman ekler
void Arraylist::insert(int index, int item)
{
    if (index < 0 || index > length)
        throw "hata";
    if (length >= capacity)

        if (capacity)
        { // capacity sifirsa birden baslatiyor
            reverse(2 * capacity);
        }
        else
        {

            reverse(1);
        }
    for (int j = length - 1; j >= index; j--)
    {
        items[j + 1] = items[j]; // dizi i den itibaren bir saga kaydirilir
    }
    items[index] = item;
    length++;
} // dizin istelilen indisine eleman ekler
int Arraylist::size() const
{
    return length;
} // dizini boyutunu verir
bool Arraylist::isEmpty() const
{
    return size() == 0;
} // diziyi bos mu diye kontrol eder
int Arraylist::elementAt(int i)
{
    if (i < 0 || i >= length)
    {
        throw "indeks disinda";
    }
    return items[i];
} // belirtilen indisteki elemani verir
void Arraylist::removeAt(int i)
{
    if (i < 0 || i >= length)
    {
        throw "indeks disinda";
    }

    for (int j = i + 1; j < length; j++)
        items[j - 1] = items[j];
    length--;
} // belirtilen indisteki elemani siler
void Arraylist::clear()
{
    length = 0;
} // diziyi sifirlar
void Arraylist::putAt(int index, int item)
{
    if (items == NULL)
    {
        throw "hata";
    }
    if (index < 0 || index > length)
        throw "hata";

    items[index] = item;
} // dizinin istenilen yerine eleman koyar  insertten farki indisteki elemanin uzerine yaziliyor olmasi
int Arraylist::first()
{
    if (length == 0)
        throw "List is empty";
    return items[0];
}
int Arraylist::last()
{
    if (length == 0)
        throw "List is empty";
    return items[length - 1];
}
int Arraylist::lastIndex()
{
    return length - 1;
}
int Arraylist::sumArray(Arraylist* arr){
    int sum=0;

    for(int i = 0;i<arr->size();i++){

        sum += arr->elementAt(i);
    }

return sum;



}
Arraylist::~Arraylist()
{
    if (items != NULL)
        delete[] items;
}