#ifndef DIMENSION_HPP
#define DIMENSION_HPP

class Dimension
{
private:
    double length;
    double width;
    double height;

public:
    Dimension();
    Dimension(double width, double height, double length);
    void setLength(double length);
    double getLength();
    void setWidth(double width);
    double getWidth();
    void setHeight(double height);
    double getHeight();
};

#endif