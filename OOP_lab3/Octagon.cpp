#include <cmath>
#include "Octagon.h"

Octagon::Octagon(): Octagon(0) {
}

Octagon::Octagon(size_t i): side(i) {
    std::cout << "Octagon created: " << side <<  std::endl;
}

Octagon::Octagon(const Octagon& orig) {
    std::cout << "Octagon copy created" <<  std::endl;
    side = orig.side;
}

Octagon& Octagon::operator=(const Octagon& right){
    if(this == &right) return *this;
    std::cout << "Octagon copied" << std::endl;
    this->side=right.side;
    return *this;
}

double Octagon::Square() {
    return (2*(1+sqrt(2))*side*side);
}