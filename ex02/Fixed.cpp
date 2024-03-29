/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:27:13 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/01 15:19:29 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) { }

Fixed::Fixed( const int n ) : rawBits(n * 256) { }

Fixed::Fixed( const float n ) : rawBits(n * 256 + (n >= 0 ? 0.5 : -0.5)) { }

Fixed::Fixed( const Fixed &rhs ) {
	*this = rhs;
}

Fixed::~Fixed() { }

int			Fixed::getRawBits( void ) const {
	return (this->rawBits); 
}

void		Fixed::setRawBits( int const raw ){ 
	this->rawBits = raw;
}

float		Fixed::toFloat( void ) const 
{
	return ((float)this->rawBits / 256);
}

int			Fixed::toInt( void ) const
{
	return (this->rawBits / 256);
}

Fixed		&Fixed::operator=( const Fixed &fixed ) {
	if (this != &fixed)
		this->rawBits = fixed.getRawBits();
	return (*this);
}

std::ostream &operator<<( std::ostream &output, Fixed const &i )
{
	output << i.toFloat();
	return (output);
}

Fixed		Fixed::operator+( const Fixed &fixed ) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed		Fixed::operator-( const Fixed &fixed ) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed		Fixed::operator*( const Fixed &fixed ) const {
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed		Fixed::operator/( const Fixed &fixed ) const {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed		&Fixed::operator++( void ) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed 		Fixed::operator++( int ) {	
	Fixed copy;

	copy = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (copy);
}

Fixed		&Fixed::operator--( void ) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed 		Fixed::operator--( int ) {
	Fixed copy;

	copy = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (copy);
}

Fixed		&Fixed::max( Fixed &fixed1, Fixed &fixed2 )
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

const Fixed	&Fixed::max( Fixed const &fixed1, Fixed const &fixed2 )
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

Fixed		&Fixed::min( Fixed &fixed1, Fixed &fixed2 )
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

const Fixed	&Fixed::min( Fixed const &fixed1, Fixed const &fixed2 )
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

bool		Fixed::operator>( const Fixed &fixed ) const {
	return (this->getRawBits() > fixed.getRawBits());
}

bool		Fixed::operator<( const Fixed &fixed ) const {
	return (this->getRawBits() < fixed.getRawBits());
}

bool		Fixed::operator<=( const Fixed &fixed ) const {
	return (this->getRawBits() <= fixed.getRawBits());
}

bool		Fixed::operator>=( const Fixed &fixed ) const {
	return (this->getRawBits() >= fixed.getRawBits());
}

bool		Fixed::operator==( const Fixed &fixed ) const {
	return (this->getRawBits() == fixed.getRawBits());
}

bool		Fixed::operator!=( const Fixed &fixed ) const {
	return (!(*this==fixed));
}

const int Fixed::fracBits = 8;