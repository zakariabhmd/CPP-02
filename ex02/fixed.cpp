#include "fixed.hpp"

Fixed::Fixed()
{
	this->fixedPoint = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copyAssignment)
{
	if(this != &copyAssignment)
	{
		this->fixedPoint = copyAssignment.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return this->fixedPoint;
}

void Fixed::setRawBits(const int fixedPoint)
{
	this->fixedPoint = fixedPoint;
}

Fixed::Fixed(const int integer)
{
	this->fixedPoint = integer * (1 << this->fractional);
}

Fixed::Fixed(const float floatNumber)
{
	this->fixedPoint =  std::roundf(floatNumber * (1 << this->fractional));
}

float Fixed::toFloat( void ) const
{
	return ((float)this->fixedPoint / (1 << this->fractional));
}

int Fixed::toInt( void ) const
{
	return ((int)this->fixedPoint / (1 << this->fractional));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &arg) const
{
	if (this->fixedPoint > arg.fixedPoint)
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed &arg) const
{
	if (this->fixedPoint < arg.fixedPoint)
		return true;
	else
		return false;
}
bool Fixed::operator>=(const Fixed &arg) const
{
		if (this->fixedPoint >= arg.fixedPoint)
		return true;
	else
		return false;
}
bool Fixed::operator<=(const Fixed &arg) const
{
		if (this->fixedPoint <= arg.fixedPoint)
		return true;
	else
		return false;
}
bool Fixed::operator==(const Fixed &arg) const
{
		if (this->fixedPoint == arg.fixedPoint)
		return true;
	else
		return false;
}
bool Fixed::operator!=(const Fixed &arg) const
{
		if (this->fixedPoint == arg.fixedPoint)
		return true;
	else
		return false;
}
Fixed Fixed::operator+(const Fixed &arg) const
{
	Fixed result;
	result = fixedPoint + arg.fixedPoint;
	return(result);
}
Fixed Fixed::operator-(const Fixed &arg) const
{
	Fixed result;
	result = fixedPoint - arg.fixedPoint;
	return(result);
}
Fixed Fixed::operator*(const Fixed &arg) const
{
	Fixed result;
	result = this->toFloat() * arg.toFloat();
	return(result);
}
Fixed Fixed::operator/(const Fixed &arg) const
{
	Fixed result;
	result = fixedPoint / arg.fixedPoint;
	return(result);
}

Fixed Fixed::operator++()
{
	this->fixedPoint += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp;
	tmp.fixedPoint = this->fixedPoint;
	this->fixedPoint +=1;
	return tmp;
}


Fixed Fixed::operator--()
{
	this->fixedPoint -= 1;
	return *this;
}


Fixed Fixed::operator--(int)
{
	Fixed tmp;
	tmp.fixedPoint = this->fixedPoint;
	this->fixedPoint +=1;
	return tmp;
}

const Fixed &Fixed::mini(const Fixed& a, const Fixed& b)
	{
		if (a < b)
			return a;
		else
			return b;
}

Fixed &Fixed::mini( Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}


const Fixed &Fixed::maxim(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed &Fixed::maxim( Fixed &a,  Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}