/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:50:32 by ple-stra          #+#    #+#             */
/*   Updated: 2023/01/11 20:09:28 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Fixed
{
private:
	int _value;
	static const int _nbBits = 8;
public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const & src);
	~Fixed();

	Fixed & operator=(Fixed const & rhs);
	bool operator>(Fixed const & rhs);
	bool operator<(Fixed const & rhs);
	bool operator>=(Fixed const & rhs);
	bool operator<=(Fixed const & rhs);
	bool operator==(Fixed const & rhs);
	bool operator!=(Fixed const & rhs);
	Fixed operator+(Fixed const & rhs);
	Fixed operator-(Fixed const & rhs);
	Fixed operator*(Fixed const & rhs);
	Fixed operator/(Fixed const & rhs);
	Fixed & operator++();
	Fixed & operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const value);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
