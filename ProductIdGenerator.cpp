#include <iostream>
#include "ProductIdGenerator.h"

ProductIdGenerator *ProductIdGenerator::instance = nullptr;

ProductIdGenerator::ProductIdGenerator()
{
    id = 0;
}

ProductIdGenerator *ProductIdGenerator::getInstance()
{
    if (ProductIdGenerator::instance == nullptr)
        ProductIdGenerator::instance = new ProductIdGenerator();
    return ProductIdGenerator::instance;
}

long ProductIdGenerator::generateId()
{
    return id += 1;
}

void ProductIdGenerator::setInitialId(long newid)
{
    id = newid;
}

ProductIdGenerator::~ProductIdGenerator()
{
    delete ProductIdGenerator::instance;
}
