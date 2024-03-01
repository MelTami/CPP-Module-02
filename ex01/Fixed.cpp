/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:00:40 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/01 14:39:56 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : rawBits(n * 256) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : rawBits(n * 256 + (n >= 0 ? 0.5 : -0.5)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &rhs ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	return (this->rawBits); 
}

void	Fixed::setRawBits( int const raw ) {
	this->rawBits = raw;
}

Fixed	&Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->rawBits = fixed.getRawBits();
	return (*this);
}


float	Fixed::toFloat( void ) const {
	return ((float)this->rawBits / 256);
}

int		Fixed::toInt( void ) const {
	return (this->rawBits / 256);
}

std::ostream	&operator<<(std::ostream &output, Fixed const &i) {
	output << i.toFloat();
	return (output);
}

const int Fixed::fracBits = 8;