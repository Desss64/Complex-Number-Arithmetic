#include "Complex.h"
#include <cmath>

//Default constructor that sets complex number to 0
Complex::Complex()
{
    realPart = 0;
    imagPart = 0;
}

//Constructor that takes real and imaginary parts as parameters
Complex::Complex(double real, double imaginary)
{
    realPart = real;
    imagPart = imaginary;
}

//Constructor that only takes the real part setting the imaginary part to 0.
Complex::Complex(double real)
{
    realPart = real;
    imagPart = 0;
}

//Returns real part of complex number
double Complex::getReal()
{
    return realPart;
}

//Returns imaginary part of complex number
double Complex::getImag()
{
    return imagPart;
}

//Sets real part to a number
void Complex::setReal(double n)
{
    realPart = n;
}

//Sets imaginary part to a number
void Complex::setImag(double n)
{
    imagPart = n;
}

//Sets real AND imaginary part to specific numbers
void Complex::set(double r, double i)
{
    realPart = r;
    imagPart = i;
}

//Overloads the output streaming operator to print out a + bi
ostream& operator <<(ostream &output, const Complex &c)
{
    //If real and imaginary part are not 0 check their signs before displaying number
    if (c.realPart != 0 && c.imagPart != 0)
    {
        if(c.imagPart > 0)
            output << c.realPart << " + " << c.imagPart << "i";

        else
            output << c.realPart << " - " << (-1 * c.imagPart) << "i";
    }

    else if(c.realPart == 0 && c.imagPart != 0)
        output << c.imagPart << "i";

    else if(c.realPart != 0)
        output << c.realPart;

    else
        output << 0;

    return output;
}

//Overloads plus operator for complex + complex
Complex Complex::operator+(const Complex &c)
{
    double newReal = realPart + c.realPart;
    double newImag = imagPart + c.imagPart;

    Complex retVal(newReal, newImag);

    return retVal;
}

//Overloads plus operator for complex + double
Complex Complex::operator+(double num)
{
    double newReal = realPart + num;

    Complex retVal(newReal, imagPart);

    return retVal;
}

//Overloads plus operator for double + complex
Complex operator+(double num, const Complex &c)
{
    double newReal = num + c.realPart;

    Complex retVal(newReal, c.imagPart);

    return retVal;
}

//Overloads minus operator for complex - complex
Complex Complex::operator-(const Complex &c)
{
    double newReal = realPart - c.realPart;
    double newImag = imagPart - c.imagPart;

    Complex retVal(newReal, newImag);

    return retVal;
}

//Overloads minus operator for complex - double
Complex Complex::operator-(double num)
{
    double newReal = realPart - num;

    Complex retVal(newReal, imagPart);

    return retVal;
}

//Overloads minus operator for double - complex
Complex operator-(double num, const Complex &c)
{
    double newReal = num - c.realPart;
    double newImag = c.imagPart;

    //If the imaginary number being subtracting is negative make it positive
    if(newImag < 0)
        newImag = newImag * -1;

    Complex retVal(newReal, newImag);

    return retVal;
}

//Overloads * operator for complex times complex
Complex Complex::operator*(const Complex &c)
{
    double newReal = (realPart*c.realPart) - (imagPart*c.imagPart);
    double newImag = (imagPart*c.realPart) + (realPart*c.imagPart);

    Complex retVal(newReal, newImag);

    return retVal;
}

//Overloads * operator for complex times double
Complex Complex::operator*(double num)
{
    double newReal = realPart * num;
    double newImag = imagPart * num;

    Complex retVal(newReal, newImag);

    return retVal;
}

//Overloads * operator for double times complex
Complex operator*(double num, const Complex &c)
{
    double newReal = num * c.realPart;
    double newImag = num * c.imagPart;

    Complex retVal(newReal, newImag);

    return retVal;
}

//Overloads / operator for complex divided by complex
Complex Complex::operator/(const Complex &c)
{
    double newReal = ((realPart*c.realPart) + (imagPart*c.imagPart))/((c.realPart*c.realPart) + (c.imagPart*c.imagPart));
    double newImag = ((imagPart*c.realPart) - (realPart*c.imagPart))/((c.realPart*c.realPart) + (c.imagPart*c.imagPart));

    Complex retVal(newReal, newImag);

    return retVal;
}

//Overloads / operator for complex divided by double
Complex Complex::operator/(double num)
{
    double newReal = realPart/num;
    double newImag = imagPart/num;

    Complex retVal(newReal, newImag);

    return retVal;
}

//Overloads / operator for double divided by complex
Complex operator/(double num, const Complex &c)
{
    //Multiples the complex number by its conjugate
    double denom = ((c.realPart*c.realPart) - (-1*(c.imagPart*c.imagPart))) + ((c.imagPart*c.realPart) +
                                                                               (-1*(c.realPart*c.imagPart)));

    //The numerators are the integer times the conjugate
    double newReal = (num * c.realPart) / denom;
    double newImag = (num * (-1*c.imagPart)) / denom;

    Complex retVal(newReal, newImag);

    return retVal;
}

//Overloads the assignment operator
const Complex Complex::operator=(const Complex &c)
{
    realPart = c.realPart;
    imagPart = c.imagPart;

    Complex retVal(realPart, imagPart);
    return retVal;
}

//Adds the two complex numbers and stores result in left complex number
void Complex::operator +=(const Complex &c)
{
    realPart = realPart + c.realPart;
    imagPart = imagPart + c.imagPart;
}

//Subtracts the right complex numbers from the left complex number and stores result in left complex number
void Complex::operator -=(const Complex &c)
{
    realPart = realPart - c.realPart;
    imagPart = imagPart - c.imagPart;
}

//Over loads the ^ operator so a complex number can be raised to an integer exponent
Complex Complex::operator^(int exp)
{
    double r = sqrt((realPart*realPart) + (imagPart*imagPart));
    double inverseTan = atan2(imagPart, realPart);

    double newReal = pow(r, exp) * cos(inverseTan*exp);
    double newImag = pow(r, exp) * sin(inverseTan*exp);

    Complex retVal(newReal, newImag);

    return retVal;
}

//Returns the modulus of the complex number
double Complex::mod()
{
    return sqrt((realPart*realPart) + (imagPart*imagPart));
}

//Overloads the equal operator to check if complex numbers are identical
bool Complex::operator ==(const Complex &c)
{
    if(realPart == c.realPart && imagPart == c.imagPart)
        return true;
    else
        return false;
}

//Overloads the != operator to check if complex numbers differ
bool Complex::operator !=(const Complex &c)
{
    if(realPart != c.realPart || imagPart != c.imagPart)
        return true;
    else
        return false;
}

//Overloads the input streaming operator to take two doubles with a space between them to load into the real and imaginary parts
istream& operator >>(istream &input, Complex &c)
{
    double real, imag;
    input >> real >> imag;

    c.realPart = real;
    c.imagPart = imag;

    return input;
}

Complex::~Complex()
{
    //dtor
}
