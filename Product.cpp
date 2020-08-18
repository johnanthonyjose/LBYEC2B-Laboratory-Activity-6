#include <string.h>
#include <stdio.h>
#include "Product.hpp"

Product::Product()
{
    ProductIdGenerator *generator = ProductIdGenerator::getInstance();
    id = generator->generateId();
    price = 0.0;
    this->setName("");
    this->setMaker("");
}

Product::Product(int price, const char *name, const char *manufacturer)
{
    ProductIdGenerator *generator = ProductIdGenerator::getInstance();
    this->id = generator->generateId();
    this->price = price;
    this->setName(name);
    this->setMaker(manufacturer);
}

long Product::getId()
{
    return this->id;
}

void Product::updateId(int newid)
{
    this->id = newid;
}

char *Product::getName()
{
    return this->name;
}

void Product::setName(const char *name)
{
    if (strlen(name) <= STRING_LENGTH)
        strcpy(this->name, name);
    else
        fprintf(stderr, "Manufactuer name cannot exceed a length of %d\n", STRING_LENGTH);
}

double Product::getPrice()
{
    return this->price;
}

void Product::setPrice(double price)
{
    if (price >= 0)
        this->price = price;
    else
        fprintf(stderr, "Price must be nonnegative number\n");
}

long Product::getQuantity()
{
    return quantity;
}

void Product::setQuantity(long quantity)
{
    if (quantity >= 0)
        this->quantity = quantity;
    else
        fprintf(stderr, "Quantity must be nonnegative number\n");
}

double Product::calcTotalCost()
{
    return quantity * price;
}

long Product::reduceStock(long difference)
{
    if (difference < 0)
        fprintf(stderr, "Amount of Stock to be removed must be nonnegative number\n");
    else if ((quantity - difference) >= 0)
        quantity -= difference;
    else
        fprintf(stderr, "%s has only %ld left. Cannot reduce by %ld\n", name, quantity, difference);

    return quantity;
}
long Product::updateStock(long difference)
{
    if (difference < 0)
        fprintf(stderr, "Amount of Stock to be removed must be nonnegative number\n");
    else if ((quantity + difference) >= 0)
        quantity += difference;
    else
        fprintf(stderr, "%s has only %ld left. Cannot reduce by %ld\n", name, quantity, difference);

    return quantity;
}

char *Product::getMaker()
{
    return this->manufacturer;
}

void Product::setMaker(const char *name)
{
    if (strlen(name) <= STRING_LENGTH)
        strcpy(this->manufacturer, name);
    else
        fprintf(stderr, "Manufactuer name cannot exceed a length of %d\n", STRING_LENGTH);
}

char *Product::getDescription()
{
    return this->description;
}

void Product::setDescription(const char *text)
{
    if (strlen(text) <= STRING_LENGTH)
        strcpy(this->description, text);
    else
    {
        fprintf(stderr, "Description cannot exceed a length of %d\n", STRING_LENGTH);
    }
}

void Product::setSize(double width, double height, double length)
{
    this->size.setWidth(width);
    this->size.setHeight(height);
    this->size.setLength(length);
}

void Product::setSize(Dimension newSize)
{
    this->size = newSize;
}

Dimension Product::getSize()
{
    return this->size;
}

char *Product::getUnit()
{
    return this->unit;
}

void Product::setUnit(const char *unit)
{
    strcpy(this->unit, unit);
}

char *Product::getStatus()
{
    return this->status;
}
void Product::setStatus(const char *status)
{
    strcpy(this->status, status);
}