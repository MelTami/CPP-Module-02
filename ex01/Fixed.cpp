/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:00:40 by mvavasso          #+#    #+#             */
/*   Updated: 2024/02/24 21:35:35 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : rawBits(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : rawBits(n){
	std::cout << "Parametric constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &rhs ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits); 
}

void Fixed::setRawBits( int const raw ){ 
	this->rawBits = raw;
}

Fixed &Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->rawBits = fixed.getRawBits();
	return (*this);
}

const int Fixed::fracBits = 8;