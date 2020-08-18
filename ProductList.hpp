#ifndef PRODUCT_LIST_HPP
#define PRODUCT_LIST_HPP
#include <vector>
#include "Product.hpp"

using namespace std;
class ProductList
{
private:
    vector<Product> list;
    const char filename[80] = "inventory.csv";
    void parseLine(char *word, long col, Product *item);

public:
    ProductList();
    void addProduct(Product item);
    Product getProduct(long id);
    void updateProduct(Product item);
    void deleteProduct(Product item);
    long getSize();
    long getIndex(Product item);
    vector<Product> getProducts();
    void setProducts(vector<Product> items);
    void loadProducts(const char *filename);
    void loadProducts();
    void saveProducts(const char *filename);
    void saveProducts();

    vector<Product> filterProductByStatus(const char *status);
    double calcTotalCost();
};

#endif