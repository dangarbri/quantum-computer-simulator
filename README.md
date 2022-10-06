# Quantum Computer Simulator
Implements the logic of a quantum computer to simulate bit manipulation as it would happen in a quantum computer.

Example:
```cxx
// Begin a computation on three qbits 000
QCompute computation(QValue({0, 0, 0}, false));

// Perform a superposition operation on bit 0.
computation.Superposition(0);

// Display the result
computation.Display();
// Prints 000, 100

// Repeat the operation
computation.Superposition(0);
computation.Display();
// prints 000, 000, interference has taken place to negate the 100's
```
