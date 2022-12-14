#pragma once

/**
 * Represents a bit. A boolean value true/false.
 */
class Bit {
public:
    Bit(bool val) : value(val) {};
    bool value = false;

};

bool operator==(const Bit& a, const Bit& b);
