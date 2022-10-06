#include "qvalue.h"
#include <iostream>
#include <sstream>

QValue::QValue(std::vector<Bit> values, bool negative) {
    value = values;
    this->negative = negative;
}

QValue::QValue(Bit value, bool negative) {
    this->value.push_back(value);
    this->negative = negative;
}

void QValue::Display() {
    std::cout << GetString() << std::endl;
}

std::string QValue::GetString() {
    std::stringstream stream;
    if (negative) {
        stream << "-";
    }

    for (auto bit : value) {
        stream << bit.value;
    }

    return stream.str();
}

QValue QValue::operator*(QValue other) {
    QValue result;
    // Allocate memory for the resulting vector so the stdlib doesn't keep expanding it every insert.
    result.value.reserve(value.size() + other.value.size());
    // Copy elements from this QValue into the resulting QValue
    result.value.insert(result.value.end(), value.begin(), value.end());
    // Copy elements from the other QValue into the result QValue
    result.value.insert(result.value.end(), other.value.begin(), other.value.end());
    // The resulting negative sign is the xor of both inputs.
    // If not negative xor not negative (i.e. positive xor positive = positive)
    // If either side is negative then positive xor negative = negative
    // If both sides are negative then negative xor negative = positive
    result.negative = negative ^ other.negative;
    return result;
}
