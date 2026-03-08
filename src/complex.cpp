#include <iostream>
#include <cmath>
#include "complex.hpp"

ComplexNumber::ComplexNumber(float real, float imaginary) {
   realPart = real;
   imaginaryPart = imaginary;
}

float ComplexNumber::real() const {
   return realPart;
}

float ComplexNumber::imaginary() const {
   return imaginaryPart;
}

ComplexNumber ComplexNumber::add(const ComplexNumber& complex_number) const {
   return ComplexNumber(realPart + complex_number.realPart,
                        imaginaryPart + complex_number.imaginaryPart);
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber& complex_number) const {
   return ComplexNumber(realPart - complex_number.realPart,
                        imaginaryPart - complex_number.imaginaryPart);
}

ComplexNumber ComplexNumber::negate() const {
   return ComplexNumber(-realPart, -imaginaryPart);
}

ComplexNumber ComplexNumber::conjugate() const {
   return ComplexNumber(realPart, -imaginaryPart);
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& complex_number) const {
   float newReal = realPart * complex_number.realPart
                   - imaginaryPart * complex_number.imaginaryPart;
   float newImag = realPart * complex_number.imaginaryPart
                   + imaginaryPart * complex_number.realPart;
   return ComplexNumber(newReal, newImag);
}

ComplexNumber ComplexNumber::divide(const ComplexNumber& complex_number) const {
   float denominator = complex_number.realPart * complex_number.realPart
                       + complex_number.imaginaryPart * complex_number.imaginaryPart;
   float newReal = (realPart * complex_number.realPart
                   + imaginaryPart * complex_number.imaginaryPart) / denominator;
   float newImag = (imaginaryPart * complex_number.realPart
                   - realPart * complex_number.imaginaryPart) / denominator;
   return ComplexNumber(newReal, newImag);
}

float ComplexNumber::magnitude() const {
   return sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
}

float ComplexNumber::phase() const {
   return atan(realPart / imaginaryPart);
}

void ComplexNumber::prettyPrint() const {

   std::cout << realPart;

   if (imaginaryPart >= 0) {
      std::cout << " + " << imaginaryPart << "i";
   }
   else {
      std::cout << " - " << -imaginaryPart << "i";
   }
   std::cout << std::endl;
}