#ifndef PRODUCTIDGENERATOR_H
#define PRODUCTIDGENERATOR_H

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

