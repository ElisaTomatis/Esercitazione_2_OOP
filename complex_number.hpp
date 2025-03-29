#pragma once
#include <iostream>
#include <concepts>

/* We constrain T to be a floating-point type */
template<typename T> requires std::floating_point<T>
class complex_number 
{
    /* Private members */
    T m_real, m_imag;

public:
    /* Default constructor */
    complex_number() : 
		m_real(0.0), m_imag(0.0) 
	{}
	
	/* A constructor for a complex number with only the real part */
	explicit complex_number(T real) 
		: m_real(real), m_imag(0.0) 
	{
		std::cout << "converting constructor called" << std::endl;
	}
    
    /* User-defined constructor. Takes two parameters, real and imaginary part */
    complex_number(T real, T imag) 
		: m_real(real), m_imag(imag) 
	{}
    
    /* Return the real part and the imaginary part */
    T real() const { 
		return m_real; 
	}
	
    T imag() const { 
		return m_imag; 
	}
    
    /* complex conjugate */
    complex_number conjugate() const {
        return complex_number(m_real, -m_imag);
    }
	
	/* è sbagliato scriverelo così: complex_number<T>& operator+=(const complex_number<T>& other) */
 	
	
    /* Operator += */
    complex_number& operator+=(const complex_number& other) {
        m_real += other.m_real;
        m_imag += other.m_imag;
        return *this;
	} 
    
    /* Operator + */
    complex_number operator+(const complex_number& other) const {
        complex_number result = *this;
        result += other;
        return result;
    }
	
	    
    /* Operator *= */
    complex_number& operator*=(const complex_number& other) {
        T new_real = m_real * other.m_real - m_imag * other.m_imag;
        T new_imag = m_real * other.m_imag + m_imag * other.m_real;
        m_real = new_real;
        m_imag = new_imag;
        return *this;
    }
    
    /* Operator * */
    complex_number operator*(const complex_number& other) const {
        complex_number result = *this;
        result *= other;
        return result;
    }
    

    // Operator += with a scalar T 
    complex_number& operator+=(const T& scalar) {
        m_real += scalar;
        return *this;
    }
    
    // Operator + with a scalar T 
    complex_number operator+(const T& scalar) const {
        complex_number result = *this;
        result += scalar;
        return result;
    }
    
    // Operator *= with a scalar T 
    complex_number& operator*=(const T& scalar) {
        m_real *= scalar;
        m_imag *= scalar;
        return *this;
    }
    
    // Operator * with a scalar T 
    complex_number operator*(const T& scalar) const {
        complex_number result = *this;
        result *= scalar;
        return result;
    }

};

/* Operator + between T and complex_number<T> */
template<typename T>
complex_number<T> operator+(const T& scalar, const complex_number<T>& c) {
    return c + scalar;
}

/* Operator * between T and complex_number<T> */
template<typename T>
complex_number<T> operator*(const T& scalar, const complex_number<T>& c) {
    return c * scalar;
}

/* Overload of <<, to make the complex printable. */
template<typename T>
std::ostream& 
operator<<(std::ostream& os, const complex_number<T>& c) {
    os << c.real();
    if (c.imag() != 0.0) {
        if (c.imag() == 1.0)
            os << "+i";
        else if (c.imag() == -1.0)
            os << "-i";
        else if (c.imag() < 0.0)
            os << c.imag() << "i";
        else
            os << "+" << c.imag() << "i";
    }
    return os;
}
