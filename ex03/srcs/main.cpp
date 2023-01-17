/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:50:20 by ple-stra          #+#    #+#             */
/*   Updated: 2023/01/17 22:30:54 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

#include "Point.hpp"

int main(int argc, char **argv)
{
	Point const a = Point(Fixed(0.5f), Fixed(0.5f));
	Point const b = Point(Fixed(2), Fixed(0.5f));
	Point const c = Point(Fixed(0.5f), Fixed(2));

	Point point;
	if (argc == 3)
		point = Point(
			Fixed(static_cast<float>(std::atof(argv[1]))),
			Fixed(static_cast<float>(std::atof(argv[2]))));
	else
		point = Point(Fixed(1), Fixed(1));

	std::cout << "The three corners of the triangle are:" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	bool pointIsInTriangle = bsp(a, b, c, point);

	std::cout << "The point " << point << " is "
		<< (pointIsInTriangle ? "in" : "not in")
		<< " the triangle" << std::endl;
	return 0;
}
