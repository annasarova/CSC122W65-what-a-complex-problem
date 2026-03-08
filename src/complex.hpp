class ComplexNumber {
private:
    float realPart;
    float imaginaryPart;

public:
    // Constructor
    ComplexNumber(float real, float imaginary);

    // Accessors
    float real() const;
    float imaginary() const;

    // Operations
    ComplexNumber add(const ComplexNumber& complex_number) const;
    ComplexNumber subtract(const ComplexNumber& complex_number) const;
    ComplexNumber negate() const;
    ComplexNumber conjugate() const;

    // Add-On (Two Credits) Multiplication and Division
    ComplexNumber multiply(const ComplexNumber& complex_number) const;
    ComplexNumber divide(const ComplexNumber& complex_number) const;

    // Math
    float magnitude() const;
    float phase() const; // Add-On (One Credit) Calculate the Phase

    // Output
    void prettyPrint() const;
};
