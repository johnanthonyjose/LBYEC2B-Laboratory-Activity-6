#ifndef INVENTORY_H
#define INVENTORY_H

#include "ProductList.h"

class Inventory
{
private:
    ProductList products;

public:
    void run();
    void addProduct();
    void updateProduct();
    void displayStocks();
    void displayInventoryCost();
};
#endif
