#include <iostream>
#include<complex>
#include "complex.h"
//this file demonstrates the use of complex.h
int main() {
	Complex z1 = Complex(4, -4);
	Complex z2 = Complex(2, 3);
	Complex sum = z1 + z2;
	Complex product = z1 * z2;
	float norm = ComplexFuncs::norm(z1);
	int x = 2;
	
	std::cout << "z1 = " << z1 << std::endl;
	std::cout << "z2 = " << z2 << std::endl;
	std::cout << "z1 + z2 = " << z1 + z2 << std::endl;
	std::cout << "sum = " << sum << std::endl;
	std::cout << "product = " << product << std::endl;
	std::cout << "norm of z1 = " << norm << std::endl;
	std::cout << "z1 + 1 = " << x + z1 << std::endl;
	std::cout << "z1 / 2 = " << z1 / 2 << std::endl;
	std::cout << "z1 / z2 = " << z1 / z2;
	return 0;
}
