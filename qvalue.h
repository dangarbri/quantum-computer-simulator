#pragma once

// Circular reference... 
#include "bit.h"
#include <vector>

/**
 * Represents a quantum value. This is some combination of bits, with a positive or negative sign for interference
 */
class QValue {
public:
    QValue(std::vector<Bit> values, bool negative);
    QValue(Bit value, bool negative);
    std::vector<Bit> value;
    bool negative = false;

    void Display();
};
