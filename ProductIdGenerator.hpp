#ifndef ITEM_ID_GENEATOR_HPP
#define ITEM_ID_GENEATOR_HPP

#include <stdlib.h>

class ProductIdGenerator
{
private:
    static ProductIdGenerator *instance;
    long id;
    ProductIdGenerator();

public:
    static ProductIdGenerator *getInstance();
    long generateId();
    void setInitialId(long id);
    ~ProductIdGenerator();
};

#endif