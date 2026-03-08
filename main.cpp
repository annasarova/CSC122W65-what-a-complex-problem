#include <iostream>

#include "src/complex.hpp"

int main() {
    ComplexNumber numberOne(5.0f, 7.0f);
    ComplexNumber numberTwo(2.5f, 3.1f);

    std::cout << "Number One: ";
    numberOne.prettyPrint();

    std::cout << "Number Two: ";
    numberTwo.prettyPrint();

    ComplexNumber numberThree = numberOne.add(numberTwo);
    std::cout << "Addition Result: ";
    numberThree.prettyPrint();

    ComplexNumber numberFour = numberOne.subtract(numberTwo);
    std::cout << "Subtraction Result: ";
    numberFour.prettyPrint();

    ComplexNumber numberFive = numberOne.negate();
    std::cout << "Negation: ";
    numberFive.prettyPrint();

    ComplexNumber numberSix = numberOne.conjugate();
    std::cout << "Conjugate: ";
    numberSix.prettyPrint();

    ComplexNumber numberSeven = numberOne.multiply(numberTwo);
    std::cout << "Multiplication Result: ";
    numberSeven.prettyPrint();

    ComplexNumber numberEight = numberOne.divide(numberTwo);
    std::cout << "Division Result: ";
    numberEight.prettyPrint();

    std::cout << "Magnitude of Number One: "
        << numberOne.magnitude() << std::endl;

    std::cout << "Phase of Number One: "
        << numberOne.phase() << std::endl;

    std::cout << "Real Part: " << numberOne.real() << std::endl;
    std::cout << "Imaginary Part: " << numberOne.imaginary() << std::endl;

    return 0;
}
