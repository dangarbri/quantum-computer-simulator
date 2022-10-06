#pragma once

#include "qvalue.h"
#include <vector>
#include <map>

typedef void (*LogicFunction)(QValue&);

/**
 * Represents a quantum computation performed on a QValue
 * Use this to perform superposition computations
 */
class QCompute {
public:
    /**
     * Begin a Quantum computation with the given starting bits.
     */
    QCompute(QValue input);

    /**
     * Stores the states of all possibilities for the computation
     */
    std::vector<QValue> states;

    /**
     * Perform a superposition operation on the given bit indices. (Treat bit positions as MSB)
     * This updates the states field.
     */
    void Superposition(std::vector<int> indices);
    
    /**
     * Perform a superposition operation on the given bit index. (Treat bit positions as MSB)
     * This updates the states field.
     */
    void Superposition(int index);

    /**
     * Executes a function that performs some operation on a QValue.
     * This is used to execute some generic logic on the current QValue being processed.
     * This function executes on all possible states of the QValue if the computation is in a superposition.
     */
    void ExecuteLogic(LogicFunction fn);

    /**
     * Performs a superposition on an individual bit in a QValue and returns the potential results.
     */
    std::vector<QValue> SuperpositionQValue(QValue qval, int index);

    void Display();

private:
    /**
     * Returns the potential values when this bit is superpositioned
     */
    std::vector<QValue> _GetSuperpositionForBit(Bit target);

    void _Interfere(int starting_index);
};
