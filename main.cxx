#include "qvalue.h"
#include "qcompute.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

void Archimedes(QValue& val) {
    if (val == "0000" ||
        val == "0001" ||
        val == "0100" ||
        val == "0101" ||
        val == "1010" ||
        val == "1011" ||
        val == "1110" ||
        val == "1111") {
        if (val.value[3] == Bit(1)) {
            val.value[3] = Bit(0);
        } else {
            val.value[3] = Bit(1);
        }
    }
}

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
    std::cout << "Result 2: " << std::endl;
    result2.Display();

    (result * result2).Display();

    QCompute compute(QValue(0, false));
    compute.Superposition(0);
    compute.Display();

    std::map<std::string, int> mapping;
    mapping["Hey"] = 1;
    std::cout << mapping["Hey"] << std::endl;

    qval.Display();
    std::cout << (qval == "00") << std::endl;

    QValue test1 {{0, 0, 0, 1}, false};
    QCompute quantum{test1};
    quantum.Superposition({0, 1, 2, 3});
    quantum.Display();
    std::cout << "------After Archimedes-------" << std::endl;
    quantum.ExecuteLogic(Archimedes);
    quantum.Display();
    std::cout << "------After Final Superposition----------" << std::endl;
    quantum.Superposition({0, 1, 2});
    quantum.Display();
}
