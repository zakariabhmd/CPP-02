#include "fixed.hpp"

Fixed::Fixed()
{
	this->fixed_p = 0;
	std::cout <<"Default constructor called"<< std::endl;

}

Fixed::Fixed(const int x)
{
	std::cout << "int constructor called " <<std::endl;
	this->fixed_p = x * ft_iterative_power(2, frac);
}
Fixed::Fixed(const float z)
{
	std::cout << "Float constructor called " <<std::endl;
	this->fixed_p = roundf(z * ft_iterative_power(2, frac));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &new_fixed)
{
	*this = new_fixed;
	std::cout <<"copy constructor called"<< std::endl;
}

Fixed &Fixed::operator =(const Fixed &new_fixed)
{
	fixed_p = new_fixed.getRawBits();
	std::cout <<"Copy assignment operator called"<<std::endl;
	return *this;
}
int Fixed::getRawBits() const
{
	return fixed_p;
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_p = raw;
}
float Fixed::toFloat()const
{
	return (float)this->fixed_p / ft_iterative_power(2, frac);
};

int Fixed::toInt( void ) const
{
	return roundf(this->fixed_p / ft_iterative_power(2, frac));
}

std::ostream& operator<<(std::ostream& COUT, const Fixed &fixed)
{
	COUT << fixed.toFloat();
	return (COUT);
}