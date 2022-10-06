#include "qvalue.h"
#include "qcompute.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

int main() {
    std::vector<Bit> bits = {0, 0};
    QValue qval(bits, false);
    qval.Display();

    std::vector<Bit> obit = {0, 0};
    std::cout << "Are they equal? " << (bits == obit) << std::endl;

    std::vector<Bit> _bits = {1, 0, 1};
    QValue _qval(_bits, true);
    _qval.Display();

    QValue result = _qval*qval;
    result.Display();

    QValue result2 = qval*_qval;
    result2.Display();

    (result * result2).Display();

    QCompute compute(qval);
    compute.Superposition(0);
    compute.Superposition(0);
    compute.Display();

    std::map<std::string, int> mapping;
    mapping["Hey"] = 1;
    std::cout << mapping["Hey"] << std::endl;
}
