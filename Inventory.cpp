#include "Inventory.hpp"

void Inventory::addProduct()
{
    Product brandnew;
    char some_string[256];
    double price;
    long quantity;
    double w, h, l;
    printf("\nEnter Product name: ");
    scanf(" %[^\n]s", some_string);
    brandnew.setName(some_string);
    printf("Enter price: ");
    scanf("%lf", &price);
    brandnew.setPrice(price);
    printf("Enter quantity: ");
    scanf("%ld", &quantity);
    brandnew.setQuantity(quantity);
    printf("Enter manufacturer: ");
    scanf(" %[^\n]s", some_string);
    brandnew.setMaker(some_string);
    printf("Enter unit: ");
    scanf(" %[^\n]s", some_string);
    brandnew.setUnit(some_string);
    printf("Enter description: ");
    scanf(" %[^\n]s", some_string);
    brandnew.setDescription(some_string);
    printf("Enter Status: ");
    scanf(" %[^\n]s", some_string);
    brandnew.setStatus(some_string);
    printf("Enter size (w,h,l): ");
    scanf("%lf,%lf,%lf", &w, &h, &l);
    Dimension size(w, h, l);
    brandnew.setSize(size);
    products.addProduct(brandnew);
    products.saveProducts();
}

void Inventory::updateProduct()
{
    long id;
    printf("Enter Product ID:");
    scanf("%ld", &id);

    Product item = products.getProduct(id);
    long quantity;
    printf("How many quantity to add/remove? ");
    scanf("%ld", &quantity);
    item.updateStock(quantity);
    products.updateProduct(item);
    products.saveProducts();
}

void Inventory::displayStocks()
{
    for (Product item : products.getProducts())
    {
        printf("ID: %ld, Product: %s, Cost: %.0f, Quantity: %ld, Manufacturer: %s\n", item.getId(), item.getName(), item.getPrice(), item.getQuantity(), item.getMaker());
    }
}

void Inventory::displayInventoryCost()
{
    printf("Total Inventory Cost: %lf\n", products.calcTotalCost());
}

void Inventory::run()
{
    products.loadProducts();

    printf("Welcome to our Online Inventroy\n");
    printf("Please pick from the choices below:\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Display Stocks\n");
    printf("4. Display Inventory Cost\n");
    printf("5. Exit\n");
    int choice = 0;
    do
    {
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 1)
            addProduct();
        else if (choice == 2)
            updateProduct();
        else if (choice == 3)
            displayStocks();
        else if (choice == 4)
            displayInventoryCost();

    } while (choice != 5);
}