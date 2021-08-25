#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <iostream>

using namespace std;

#define max_capacity 10

template<class T>
class Inventory // used to handle everything to do with the Inventory
{
public:
   vector<T*> listItem;
   int maxCapacity;

public:
   Inventory();
   //Inventory(const std::vector<Engimon>& EngimonList, int n);
   ~Inventory();
  
   void addItem(T *ItemMasuk);
   void removeItem(T *wantDelete);
   void printInventory();
   int countItem();
};

#endif