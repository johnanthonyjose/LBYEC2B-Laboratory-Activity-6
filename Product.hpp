#ifndef ITEM_HPP
#define ITEM_HPP

#include <stdlib.h>
#include "ProductIdGenerator.hpp"
#include "Dimension.hpp"

#define STRING_LENGTH 256

class Product
{
private:
    int id;
    char name[STRING_LENGTH];
    double price;
    long quantity;
    char manufacturer[STRING_LENGTH];
    char description[STRING_LENGTH];
    char unit[STRING_LENGTH];
    char status[STRING_LENGTH];
    Dimension size;

public:
    Product();
    Product(int price, const char *name, const char *manufacturer);
    long getId();
    void updateId(int id);
    char *getName();
    void setName(const char *name);
    double getPrice();
    void setPrice(double price);
    long getQuantity();
    void setQuantity(long quantity);
    long updateStock(long difference);
    long reduceStock(long difference);
    double calcTotalCost();
    char *getMaker();
    void setMaker(const char *name);
    char *getDescription();
    void setDescription(const char *text);
    char *getStatus();
    char *getUnit();
    void setUnit(const char *unit);
    void setStatus(const char *status);
    void setSize(double width, double height, double length);
    void setSize(Dimension newSize);
    Dimension getSize();
};

#endif