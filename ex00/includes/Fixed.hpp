/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:50:32 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/14 05:24:20 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
private:
	int _value;
	static const int _nbBits = 8;

public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();

	Fixed &operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const value);
};
