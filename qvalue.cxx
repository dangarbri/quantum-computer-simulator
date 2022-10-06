#include "qvalue.h"
#include <iostream>

QValue::QValue(std::vector<Bit> values, bool negative) {
    value = values;
    this->negative = negative;
}

QValue::QValue(Bit value, bool negative) {
    this->value.push_back(value);
    this->negative = negative;
}

void QValue::Display() {
    if (negative) {
        std::cout << "-";
    }

    for (auto bit : value) {
        std::cout << bit.value;
    }

    std::cout << std::endl;
}
