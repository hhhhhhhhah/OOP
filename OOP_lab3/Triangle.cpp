#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(0, 0, 0) {
    std::cout << "Triangle created: default" << std::endl;
}

Triangle::Triangle(size_t i, size_t j, size_t k) : side_a(i), side_b(j), side_c(k) {
    std::cout << "Triangle created: " << side_a << ", " << side_b << ", " << side_c << std::endl;
}

Triangle::Triangle(const Triangle& orig) {
    std::cout << "Triangle copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
    side_c = orig.side_c;
}

double Triangle::Square() {
    double p = (side_a + side_b + side_c)/2.0;
    return sqrt(p * (p-side_a) * (p-side_b) * (p-side_c));
}
void Triangle::Print() {
    std::cout << "Triangle: side_a = " << this->side_a << "side_b = " << this->side_b << "side_c = " << this->side_c << std::endl;
}

Triangle& Triangle::operator=(const Triangle& right) {
    if (this == &right) return *this;
    std::cout << "Triangle copied" << std::endl;
    side_a = right.side_a;
    side_b = right.side_b;
    side_c = right.side_c;
    return *this;
}

Triangle::~Triangle() {
    std::cout << "Triangle deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Triangle& obj) {
    os << "a=" << obj.side_a << ", b=" << obj.side_b << ", c=" << obj.side_c;
    return os;
}