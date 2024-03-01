/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:27:08 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/01 14:37:30 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int					rawBits;
	static const int	fracBits; 
public:
    Fixed();
	Fixed( const int n );
    Fixed( const float n);
	Fixed( Fixed const &rhs );
	~Fixed();
    Fixed	            &operator=( Fixed const &fixed );
    int                 getRawBits( void ) const;
    void                setRawBits( int const raw );
    float               toFloat( void ) const;
    int                 toInt( void ) const;

    Fixed				operator+( Fixed const & fixed ) const;
	Fixed				operator-( Fixed const & fixed ) const;
	Fixed				operator*( Fixed const & fixed ) const;
	Fixed				operator/( Fixed const & fixed ) const;

	Fixed				&operator++( void );
	Fixed				operator++( int );
	Fixed				&operator--( void );
	Fixed				operator--( int );

	bool				operator>( Fixed const & fixed ) const;
	bool				operator<( Fixed const & fixed ) const;
	bool				operator>=( Fixed const & fixed ) const;
	bool				operator<=( Fixed const & fixed ) const;
	bool				operator==( Fixed const & fixed ) const;
	bool				operator!=( Fixed const & fixed ) const;

	static Fixed 		&max( Fixed &fixed1, Fixed &fixed2 );
	static const Fixed	&max( Fixed const &fixed1, Fixed const &fixed2 );
	static Fixed		&min( Fixed &fixed1, Fixed &fixed2 );
	static const Fixed	&min( Fixed const &fixed1, Fixed const &fixed2 );

};

std::ostream & operator<<( std::ostream &output, Fixed const &i );

#endif