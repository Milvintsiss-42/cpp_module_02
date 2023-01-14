/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:50:20 by ple-stra          #+#    #+#             */
/*   Updated: 2023/01/14 15:56:04 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

#include "Fixed.hpp"

int main(int argc, char **argv)
{
	Fixed a;
	Fixed b;

	if (argc == 3)
	{
		a = Fixed(static_cast<float>(std::atof(argv[1])));
		b = Fixed(static_cast<float>(std::atof(argv[2])));
	}
	else
	{
		a = Fixed(10);
		b = Fixed(42);
	}

	std::cout << "a value: " << a << std::endl;
	std::cout << "b value: " << b << std::endl;
	if (a > b)
		std::cout << "a is bigger" << std::endl;
	if (a < b)
		std::cout << "b is bigger" << std::endl;
	if (a >= b)
		std::cout << "a is bigger or equal" << std::endl;
	if (a <= b)
		std::cout << "b is bigger or equal" << std::endl;
	if (a == b)
		std::cout << "a and b are equal" << std::endl;
	if (a != b)
		std::cout << "a and b are not equal" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "a value: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a value: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a value: " << a << std::endl;
	std::cout << "b value: " << b << std::endl;
	std::cout << "b--: " << b-- << std::endl;
	std::cout << "b value: " << b << std::endl;
	std::cout << "--b: " << --b << std::endl;
	std::cout << "b value: " << b << std::endl;
	std::cout << "Biggest fixed: " << Fixed::max(a, b) << std::endl;
	std::cout << "Smallest fixed: " << Fixed::min(a, b) << std::endl;

	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	return 0;
}
