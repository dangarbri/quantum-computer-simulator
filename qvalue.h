#pragma once

// Circular reference... 
#include "bit.h"
#include <string>
#include <vector>

/**
 * Represents a quantum value. This is some combination of bits, with a positive or negative sign for interference
 */
class QValue {
public:
    /**
     * Constructs a QValue from a list of bits
     */
    QValue(std::vector<Bit> values, bool negative);

    /**
     * Constructs a QValue from a single bit
     */
    QValue(Bit value, bool negative);

    /**
     * Construct an empty QValue
     */
    QValue() {};

    /**
     * Store the string of bits
     */
    std::vector<Bit> value;

    /**
     * Store the overall sign of this qvalue
     */
    bool negative = false;

    /**
     * Print the contents of this QValue to the console.
     */
    void Display();

    std::string GetString();

    /**
     * Combine two QValues. Order matters.
     */
    QValue operator*(QValue other);
};

bool operator== (const QValue& val, const std::string& str);
