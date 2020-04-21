#pragma once
#include"complex_tf.h"
//implementations for Complex and ComplexFuncs
/*
this class was written before I decided to spilt up the declarations and implementation
in order to move methods like inverse, sine, norm from Complex class to another class I had to split things up
complex_tf.h header file includes all the declarations for Complex class its member and non member functions and also
the declarations for ComplexFunc class
class Complex {
	public:
		float real;//real part of the number 
		float imag;//imaginary part of the number
		Complex() {
			this->real = 0;
			this->imag = 0;
		}
		Complex(int real, int imag) {
			this->real = (float)real;
			this->imag = (float)imag;
		}
		Complex(float real, float imag) {
			this->real = real;
			this->imag = imag;
		}

		//complex operations
		Complex operator+(const Complex& z) {
			return Complex(this->real + z.real, this->imag + z.imag);
		}
		Complex operator-(const Complex& z) {
			return Complex(this->real - z.real, this->imag - z.imag);
		}
		
		z1 = a+bj
		z2 = c+dj
		z1*z2 = (ac -bd) + j(ad+bc)
		
		Complex operator*(const Complex& z) {
			float real = this->real * z.real - this->imag * z.imag;
			float imag = this->real * z.imag + this->imag * z.real;
			return Complex(real, imag);
		}
		Complex operator/(const Complex& z) {
			return (*this) * ComplexFuncs::inverse(z);
		}
		//real operations, friend functions are used here to make the operations commutative
		Complex operator+(const float& x) {
			return Complex(this->real + x, this->imag);
		}
		
		Complex operator-(const float& x) {
			return Complex(this->real - x, this->imag);
		}
		Complex operator*(const float& x) {
			return Complex(this->real * x, this->imag * x);
		}
		Complex operator/(const float& x) {
			return Complex(this->real / x, this->imag / x);
		}
		friend Complex operator+(const float& x, Complex& z) {
			return z + x;
		}
		friend Complex operator-(const float& x, Complex& z) {
			return z - x;
		}
		friend Complex operator*(const float& x, Complex& z) {
			return z * x;
		}
		friend Complex operator/(const float& x, Complex& z) {
			Complex inv = ComplexFuncs::inverse(z);
			return x * inv;
		}
		
		friend std::ostream& operator<<(std::ostream& os, const Complex& z) {
			if(z.imag<0){
				os << z.real << z.imag << "j"; // j^2 = -1
			}
			else {
				os << z.real << "+" << z.imag << "j";
			}
				
			return os;
		}
};
*/


//constructo definitions for Complex class
Complex::Complex() {
	this->real = 0.0f;
	this->imag = 0.0f;
}
Complex::Complex(int real, int imag) {
	this->real = (float)real;
	this->imag = (float)imag;
}
Complex::Complex(float real, float imag) {
	this->real = real;
	this->imag = imag;
}
//operator overloads for Complex class

Complex Complex::operator+(const Complex& z) {
	return Complex(this->real + z.real, this->imag + z.imag);
}
Complex Complex::operator-(const Complex& z) {
	return Complex(this->real - z.real, this->imag - z.imag);
}
Complex Complex::operator*(const Complex& z) {
	float real = this->real * z.real - this->imag * z.imag;
	float imag = this->real * z.imag + this->imag * z.real;
	return Complex(real, imag);
}
Complex Complex::operator/(const Complex& z) {
	return (*this) * ComplexFuncs::inverse(z);
}
//more operator overloads for Complex class
Complex Complex::operator+(const float& x){
	return Complex(this->real + x, this->imag);
}
Complex Complex::operator-(const float& x){
	return Complex(this->real - x, this->imag);
}
Complex Complex::operator*(const float& x){
	return Complex(this->real * x, this->imag * x);
}
Complex Complex::operator/(const float& x){
	return Complex(this->real / x, this->imag / x);
}

//friend function definitions for Complex class, idk why const Complex& wont work... yes i did write it in the declartion 
// but doesnt work gives an error
Complex operator+(const float& x, Complex& z) {
	return z + x;
}
Complex operator-(const float& x, Complex& z) {
	return z - x;
}
Complex operator*(const float& x, Complex& z) {
	return z * x;
}
Complex operator/(const float& x, Complex& z) {
	Complex inv =  ComplexFuncs::inverse(z);
	return x * inv;//unknown bug cant write x * ComplexFuncs::inverse(z) gives error no operator * matches operands 
}
//output << overload.... this function still confuses me... idk why std::ostream& is passed
std::ostream& operator<<(std::ostream& os, const Complex& z) {
	if (z.imag < 0) {
		os << z.real << z.imag << "j"; // j^2 = -1
	}
	else {
		os << z.real << "+" << z.imag << "j";
	}

	return os;
}

/*
the original ComplexFuncs class. After writing it I realized that I couldn't use it in my Complex class as it had not been declared yet
class ComplexFuncs {
	public:
		//inverse of z
			/*
			z = a+bj
			inverse(z) = a/(a^2+b^2) - jb/(a^2+b^@2)
			
		static Complex inverse(const Complex& z) {
			float real = z.real / (pow(z.real, 2) + pow(z.imag, 2));
			float imag = -z.imag / (pow(z.real, 2) + pow(z.imag, 2));
			return Complex(real, imag);
		}
		//calculate the norm of the complex number

		static float norm(const Complex& z) {
			float norm = sqrt(pow(z.real, 2) + pow(z.imag, 2));
			return norm;
		}

		//sine of complex number sin(a+bj)=sin(a)cosh(b)+jcos(a)sinh(b)
		static Complex sine(const Complex& z) {
			float real = (std::sin(z.real)) * (std::cosh(z.imag));
			float imag = (std::cos(z.real)) * (std::sinh(z.imag));
			return Complex(real, imag);
		}
};
*/
//implementation of ComplexFuncs

Complex ComplexFuncs::inverse(const Complex& z) {
	float real = z.real / (pow(z.real, 2) + pow(z.imag, 2));
	float imag = -z.imag / (pow(z.real, 2) + pow(z.imag, 2));
	return Complex(real, imag);
}

float ComplexFuncs::norm(const Complex& z) {
	float norm = sqrt(pow(z.real, 2) + pow(z.imag, 2));
	return norm;
}

Complex ComplexFuncs::sine(const Complex& z) {
	float real = (std::sin(z.real)) * (std::cosh(z.imag));
	float imag = (std::cos(z.real)) * (std::sinh(z.imag));
	return Complex(real, imag);
}