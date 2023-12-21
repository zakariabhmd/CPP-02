#include "fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Destructor created with default constructor" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Destructor copied" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}