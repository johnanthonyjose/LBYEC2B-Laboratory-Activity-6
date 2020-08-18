#include <stdlib.h>
#include <stdio.h>
#include "ProductList.hpp"

ProductList::ProductList()
{
}

void ProductList::addProduct(Product item)
{
    list.push_back(item);
}

Product ProductList::getProduct(long id)
{
    int i;
    Product temp;
    for (i = 0; i < list.size(); i++)
    {
        if (list[i].getId() == id)
        {
            temp = list[i];
            break;
        }
    }
    return temp;
}

void ProductList::updateProduct(Product item)
{
    int i;
    for (i = 0; i < list.size(); i++)
    {
        if (list[i].getId() == item.getId())
        {
            list[i] = item;
            break;
        }
    }
}

void ProductList::deleteProduct(Product item)
{
    int i;
    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        if (iter->getId() == item.getId())
            list.erase(iter);
    }
}

long ProductList::getSize()
{
    return list.size();
}

long ProductList::getIndex(Product item)
{
    long index = -1;
    long i;
    for (i = 0; i < list.size(); i++)
    {
        if (list[i].getId() == item.getId())
        {
            index = i;
            break;
        }
    }
    return index;
}

vector<Product> ProductList::getProducts()
{
    return list;
}
void ProductList::setProducts(vector<Product> items)
{
    list = items;

    long maxValue = 0;
    for (Product item : items)
    {
        if (item.getId() > maxValue)
            maxValue = item.getId();
    }
    ProductIdGenerator *gen = ProductIdGenerator::getInstance();
    gen->setInitialId(maxValue);
}

void ProductList::parseLine(char *word, long col, Product *item)
{
    char *endWord;
    Dimension size;
    switch (col)
    {
    case 1: //ID
    {
        long temp = strtol(word, &endWord, 0);
        item->updateId(temp);
    }
    break;
    case 2: //Name
        item->setName(word);
        break;
    case 3: //Price
    {
        double temp2 = strtod(word, &endWord);
        item->setPrice(temp2);
    }
    break;
    case 4: //Quantity
    {
        long qty = strtol(word, &endWord, 0);
        item->setQuantity(qty);
    }
    break;
    case 5: //Manufacturer
        item->setMaker(word);
        break;
    case 6: //Description
        item->setDescription(word);
        break;
    case 7: // Unit
        item->setUnit(word);
        break;
    case 8: //Status
        item->setStatus(word);
        break;
    case 9: //Width
    {
        double newwidth = strtod(word, &endWord);
        size = item->getSize();
        size.setWidth(newwidth);
        item->setSize(size);
        break;
    }
    case 10: //Height
    {
        double newHeight = strtod(word, &endWord);
        size = item->getSize();
        size.setHeight(newHeight);
        item->setSize(size);
        break;
    }
    case 11: //Length
    {
        double newLength = strtod(word, &endWord);
        size = item->getSize();
        size.setLength(newLength);
        item->setSize(size);
        break;
    }
    default:
        break;
    }
}

void ProductList::loadProducts(const char *filename)
{
    FILE *fp;
    char buffer[2048];
    char word[2048];
    char token_pos = 0;
    int record_count = 0; //Current count of row
    int field_count = 0;  //Current count of column
    fp = fopen(filename, "r");

    if (!fp)
    {
        printf("Error reading CSV File. Make sure filename is correct.");
        return;
    }
    vector<Product> newList;
    int isHeader = 1;
    //fgets gets 4096 characters on the pointed file. It will be stored on buffer
    //If fgets is successful, then we will continue with the loop
    //Else if it reaches end of file, then the loop stops
    //Note: At index 4096, fgets puts a null character
    //Asumes that the whole row AT MOST 4096 characters.
    while (fgets(buffer, 4096, fp))
    {

        //We assume to get the header at our first read, So we want to skip it.
        if (isHeader == 1)
        {
            isHeader = 0;
            continue;
        }

        //Let's start parsing the column
        field_count = 0;
        int i = 0;       //Index of the current character
        int isquote = 0; //0 means false
        Product currentProduct;
        do
        {
            word[token_pos] = buffer[i]; //Store current char on word
            token_pos++;

            if (!isquote && (buffer[i] == ',' || buffer[i] == '\n'))
            {
                word[token_pos - 1] = 0; //Terminate it to be formally considered as a string
                token_pos = 0;           //Reset index so give way for the next word on the next loop
                field_count += 1;        //Sets the column number
                parseLine(word, field_count, &currentProduct);
            }

            //In CSV spec, If you see a phrase enclosed in double quote, it is considered as one field
            //If current char is a double quote, and the next char is not a double quote
            if (buffer[i] == '"' && buffer[i + 1] != '"')
            {
                isquote = !isquote; //Invert the current status.
                token_pos--;        //In order not to include double quote on the actual word content
            }

            //In CSV spec, it allows a word enclosed in double quote to have double quote inside
            //If current char is double quote and the next one is also a double quote
            if (buffer[i] == '"' && buffer[i + 1] == '"')
            {
                i = i + 1; //So that we can only get one double quote.
            }

            i = i + 1;
        } while (buffer[i]); //Continue with the loop as long as it's a character.
        //However, when it sees a null character, it will stop.

        record_count += 1; //Increment record count by 1
        newList.push_back(currentProduct);
    }
    fclose(fp);
    setProducts(newList);

    return; //Reduce one to reduce the header
}

void ProductList::loadProducts()
{
    loadProducts(filename);
}

void ProductList::saveProducts(const char *filename)
{
    FILE *fp;

    fp = fopen(filename, "w");

    if (!fp)
    {
        printf("Error reading CSV File. Make sure filename is correct.");
        return;
    }

    //Write Header
    char header[256];
    sprintf(header, "ID, Name, Price, Quantity, Manufacturer, Description, Unit, Status, Width, Height, Length\n");
    fprintf(fp, "%s", header);

    int i;
    for (Product item : list)
    {
        char *line = (char *)malloc(4096 * sizeof(char));
        Dimension dim = item.getSize();
        sprintf(line, "%ld,\"%s\",%lf,%ld,\"%s\",\"%s\",\"%s\",\"%s\",%lf,%lf,%lf\n", item.getId(), item.getName(), item.getPrice(), item.getQuantity(), item.getMaker(), item.getDescription(), item.getUnit(), item.getStatus(), dim.getWidth(), dim.getHeight(), dim.getLength());
        fprintf(fp, "%s", line);
        free(line);
    }

    fclose(fp);
}

void ProductList::saveProducts()
{
    saveProducts(filename);
}

vector<Product> ProductList::filterProductByStatus(const char *status)
{
    vector<Product> targetProducts;
    int i = 0;
    for (i = 0; i < list.size(); i++)
    {
        if (strcmp(list[i].getStatus(), status) == 0)
            targetProducts.push_back(list[i]);
    }
    return targetProducts;
}

double ProductList::calcTotalCost()
{
    double total = 0;
    for (Product item : list)
    {
        total += item.calcTotalCost();
    }
    return total;
}