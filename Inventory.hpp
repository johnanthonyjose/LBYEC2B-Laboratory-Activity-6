#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "ProductList.hpp"

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