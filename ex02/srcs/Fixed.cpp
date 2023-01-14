/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:50:29 by ple-stra          #+#    #+#             */
/*   Updated: 2023/01/12 15:54:51 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cmath>

#include "Fixed.hpp"

static float ft_pow(int nb, int exponant);

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(int const value)
{
	this->_value = value << 8;
}

Fixed::Fixed(float const value)
{
	this->_value = static_cast<int>(roundf(value)) << _nbBits;
	this->_value += static_cast<int>(roundf((value - roundf(value))
		* ft_pow(2, _nbBits)));
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const value)
{
	this->_value = value;
}

int Fixed::toInt(void) const
{
	return this->_value >> _nbBits;
}

float Fixed::toFloat(void) const
{
	int integerPart = this->_value >> _nbBits;
	float fractionalPart = (this->_value - (integerPart << _nbBits))
		/ ft_pow(2, _nbBits);
	return integerPart + fractionalPart;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	this->_value = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed newFixed = Fixed();
	newFixed.setRawBits(this->getRawBits() + rhs.getRawBits());
	return newFixed;
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed newFixed = Fixed();
	newFixed.setRawBits(this->getRawBits() - rhs.getRawBits());
	return newFixed;
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	Fixed newFixed = Fixed();
	newFixed.setRawBits((this->getRawBits() * rhs.getRawBits()) >> _nbBits);
	return newFixed;
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	Fixed newFixed = Fixed();
	newFixed.setRawBits((this->getRawBits() / rhs.getRawBits()) << _nbBits);
	return newFixed;
}

// Prefix increment
Fixed & Fixed::operator++()
{
	this->_value++;
	return *this;
}

// Postfix increment
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	++*this;
	return tmp;
}

// Prefix decrement
Fixed & Fixed::operator--()
{
	this->_value--;
	return *this;
}

// Postfix decrement
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	--*this;
	return tmp;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	return a > b ? a : b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	return a > b ? a : b;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	return a < b ? a : b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	return a < b ? a : b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

static float ft_pow(int nb, int exponant)
{
	float value = 1.0;
	for (int i = 0; i < exponant; i++)
		value *= nb;
	return value;
}
