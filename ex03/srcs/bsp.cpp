/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:28:05 by ple-stra          #+#    #+#             */
/*   Updated: 2023/01/18 17:30:48 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const signedArea = Fixed(0.5f)
		* (Fixed(-1) * b.y() * c.x()
			+ a.y() * (Fixed(-1) * b.x() + c.x())
			+ a.x() * (b.y() - c.y())
			+ b.x() * c.y());

	Fixed const s = (Fixed(1) / (Fixed(2) * signedArea))
		* (a.y() * c.x() - a.x() * c.y()
			+ (c.y() - a.y()) * point.x()
			+ (a.x() - c.x()) * point.y());
	Fixed const t = (Fixed(1) / (Fixed(2) * signedArea))
		* (a.x() * b.y() - a.y() * b.x()
			+ (a.y() - b.y()) * point.x()
			+ (b.x() - a.x()) * point.y());

	std::cout << std::endl << "Signed Area: " << signedArea << std::endl;
	std::cout << "s: " << s << std::endl;
	std::cout << "t: " << t << std::endl << std::endl;
	return (s > Fixed(0) && t > Fixed(0) && Fixed(1) - s - t > Fixed(0));
}
