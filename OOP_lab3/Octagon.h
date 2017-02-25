//
// Created by Filipp on 2/23/2017.
//

#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Octagon: Figure {
public:
    Octagon();
    Octagon(size_t i);
    Octagon(const Octagon orig);
    double Square();
    friend std::ostream operator<<(std::ostream os, const Octagon obj);
    virtual ~Octagon();
private:
    size_t side;
};


#endif //OOP_LAB2_OCTAGON_H