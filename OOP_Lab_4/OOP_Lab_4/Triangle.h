#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Triangle: public Figure {
public:
    Triangle();
    Triangle(size_t i,size_t j,size_t k);
    Triangle(const Triangle& orig);
    double Square();
    void Print();
    friend std::ostream& operator<<(std::ostream& os, const Triangle& obj);
    Triangle& operator=(const Triangle& right);

    virtual ~Triangle();

private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
};

#endif //OOP_LAB2_TRIANGLE_H
