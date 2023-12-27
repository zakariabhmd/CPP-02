#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class Fixed{
	private:
		int fixed_p;
		static const int frac = 8;
	public:
		Fixed();
		Fixed(const Fixed &new_fixed);
		Fixed &operator =(const Fixed &new_fixed);
		int getRawBits() const;
		void setRawBits( int const raw );
		~Fixed();
};

#endif