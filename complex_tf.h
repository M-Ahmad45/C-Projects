//#pragma once
#ifndef _IOSTREAM_
#include <iostream>
#endif // !_IOSTREAM_
//this header file contains the declarations for Complex and ComplexFuns classes. Include complex.h in cpp file to use the 
// functionality

class Complex {
public:
	float real, imag;
	//Constructors
	Complex();
	Complex(int real, int imag);
	Complex(float real, float imag);
	//complex only operations
	Complex operator+(const Complex& z);
	Complex operator-(const Complex& z);
	Complex operator*(const Complex& z);
	Complex operator/(const Complex& z);
	//complex and real operations
	Complex operator+(const float& x);
	Complex operator-(const float& x);
	Complex operator*(const float& x);
	Complex operator/(const float& x);
	//friend(non member) functions to allow commutative operations
	friend Complex operator+(const float& x, Complex& z);
	friend Complex operator-(const float& x, Complex& z);
	friend Complex operator*(const float& x, Complex& z);
	friend Complex operator/(const float& x, Complex& z);
	//overload the ostream to allow printing to console
	friend std::ostream& operator<<(std::ostream& os, const Complex& z);
};


class ComplexFuncs {
public:
	static Complex inverse(const Complex& z);
	static float norm(const Complex& z);
	static Complex sine(const Complex& z);
};
