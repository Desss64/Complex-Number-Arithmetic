#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

class Complex
{
private:
    double realPart;
    double imagPart;

public:
    Complex();
    Complex(double, double);
    Complex(double);
    ~Complex();
    double mod();

    //Getters for real and imaginary parts
    double getReal();
    double getImag();

    //Setters for real and imaginary parts
    void setReal(double);
    void setImag(double);
    void set(double, double);

    const Complex operator=(const Complex&);
    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator*(const Complex&);
    Complex operator/(const Complex&);
    Complex operator^(int);

    Complex operator+(double);
    Complex operator-(double);
    Complex operator*(double);
    Complex operator/(double);

    void operator +=(const Complex&);
    void operator -=(const Complex&);

    friend Complex operator+(double, const Complex&);
    friend Complex operator-(double, const Complex&);
    friend Complex operator*(double, const Complex&);
    friend Complex operator/(double, const Complex&);

    bool operator ==(const Complex&);
	bool operator !=(const Complex&);

    friend ostream& operator <<(ostream&, const Complex&);
    friend istream& operator >>(istream&, Complex&);
};

#endif // COMPLEX_H
