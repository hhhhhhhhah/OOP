
#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Octagon: public Figure {
public:
    Octagon();
    Octagon(size_t i);
    Octagon(const Octagon& orig);
    double Square();
    friend std::ostream operator<<(std::ostream os, const Octagon obj);
    Octagon&operator=(const Octagon& right);
    virtual ~Octagon();
private:
    size_t side;
};


#endif //OOP_LAB2_OCTAGON_H
