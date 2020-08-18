#include <stdlib.h>
#include <stdio.h>
#include "Dimension.hpp"

Dimension::Dimension(double width, double height, double length)
{
    this->setHeight(height);
    this->setWidth(width);
    this->setLength(length);
}

Dimension::Dimension()
{
    this->height = 0;
    this->width = 0;
    this->length = 0;
}

void Dimension::setHeight(double height)
{
    if (height >= 0)
        this->height = height;
    else
        fprintf(stderr, "Height must be nonnegative.");
}

double Dimension::getHeight()
{
    return height;
}

void Dimension::setLength(double length)
{
    if (length >= 0)
        this->length = length;
    else
        fprintf(stderr, "Length must be nonnegative.");
}

double Dimension::getLength()
{
    return length;
}

void Dimension::setWidth(double width)
{
    if (width >= 0)
        this->width = width;
    else
        fprintf(stderr, "Width must be nonnegative.");
}

double Dimension::getWidth()
{
    return width;
}
