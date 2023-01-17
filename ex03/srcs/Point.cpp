/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:07:02 by ple-stra          #+#    #+#             */
/*   Updated: 2023/01/17 22:30:01 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

Point::Point()
{
}

Point::Point(Point const & src) : _x(src.x()), _y(src.y())
{
}

Point::Point(Fixed const & x, Fixed const & y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Point & Point::operator=(Point const & rhs)
{
	this->~Point();
	new (this) Point(rhs);
	return *this;
}

Fixed Point::x() const
{
	return this->_x;
}

Fixed Point::y() const
{
	return this->_y;
}

std::ostream & operator<<(std::ostream & o, Point const & rhs)
{
	o << "Point(" << rhs.x() << ", " << rhs.y() << ")";
	return o;
}