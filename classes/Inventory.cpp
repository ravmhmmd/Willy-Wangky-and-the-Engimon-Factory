#include "Inventory.h"
template<class T>
Inventory<T>::Inventory()
{
    maxCapacity = max_capacity;
}
template<class T>
Inventory<T>::~Inventory(){}

template<class T>
void Inventory<T>::addItem(T *ItemMasuk)
{
    
    if(countItem() < maxCapacity){
        listItem.push_back(ItemMasuk);
    }else{
        cout << "Inventory Penuh! \n";
    }

}
template<class T>
void Inventory<T>::removeItem(T *wantDelete)
{
    listItem.erase(remove(listItem.begin(), listItem.end(), wantDelete), listItem.end());
}
template<class T>
int Inventory<T>::countItem(){
    return listItem.size();
}
template<class T>
void Inventory<T>::printInventory(){

}


