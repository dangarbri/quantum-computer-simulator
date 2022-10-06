#include "qcompute.h"
#include <iostream>

QCompute::QCompute(QValue input) {
    states.push_back(input);
}

void QCompute::Superposition(std::vector<int> indices) {
    for (auto idx : indices) {
        Superposition(idx);
    }
}

void QCompute::Superposition(int index) {
    int state_size = states.size();
    int i;
    for (i = 0; i < state_size; i++) {
        for (auto possibility : SuperpositionQValue(states[i], index)) {
            states.push_back(possibility);
        }
    }

    // Remove the states that we performed the superpositions on, since they have changed.
    states.erase(states.begin(), states.begin() + i);

    _Interfere(0);
}

void QCompute::_Interfere(int starting_index) {
    for (int i = starting_index; i < states.size(); i++) {
        QValue current = states[i];
        for (int j = i + 1; j < states.size(); j++) {
            QValue other = states[j];
            // Check for opposite signs
            if (current.negative != other.negative) {
                // And equality
                if (current.value == other.value) {
                    // Then remove both.
                    // j is always after i, so delete it first.
                    states.erase(states.begin() + j);
                    // delete i
                    states.erase(states.begin() + i);
                    // Don't continue in this loop since i/j are broken. Start over at the current position
                    return _Interfere(i);
                }
            }
        }
    }
}

std::vector<QValue> QCompute::SuperpositionQValue(QValue qval, int index) {
    Bit target = qval.value[index];
    std::vector<QValue> possibilities = _GetSuperpositionForBit(target);
    // Two new QValues will be created
    QValue result_a = qval;
    result_a.value[index].value = possibilities[0].value[0].value;

    QValue result_b = qval;
    result_b.value[index] = possibilities[1].value[0].value;
    result_b.negative = result_b.negative ^ possibilities[1].negative;

    return {result_a, result_b};
}

std::vector<QValue> QCompute::_GetSuperpositionForBit(Bit target) {
    std::vector<QValue> result;
    result.push_back(QValue(0, false));
    if (target.value == false) {
        result.push_back(QValue(1, false));
    } else {
        QValue val = QValue(1, true);
        result.push_back(val);
    }
    return result;
}

void QCompute::Display() {
    std::cout << "Current State: " << std::endl;
    for (auto qval : states) {
        std::cout << "    " << qval.GetString() << std::endl;
    }
}
