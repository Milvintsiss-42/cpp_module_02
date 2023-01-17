/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:04:56 by ple-stra          #+#    #+#             */
/*   Updated: 2023/01/17 19:03:27 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(Point const & src);
	Point(Fixed const & x, Fixed const & y);
	~Point();

	Point & operator=(Point const & rhs);

	Fixed x() const;
	Fixed y() const;
};

std::ostream & operator<<(std::ostream & o, Point const & rhs);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
