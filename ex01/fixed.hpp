#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
	private:
		int fixed_p;
		static const int frac = 8;
	public:
		Fixed();
		Fixed(const int x);
		Fixed(const float x);
		Fixed(const Fixed &new_fixed);
		Fixed &operator =(const Fixed &new_fixed);
		int getRawBits() const;
		void setRawBits( int const raw );
		float toFloat()const;
		int toInt( void ) const;
		~Fixed();
};

int	ft_iterative_power(int nb, int power);
std::ostream& operator<<(std::ostream& COUT, const Fixed &fixed);

#endif