/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:00:37 by mvavasso          #+#    #+#             */
/*   Updated: 2024/02/24 22:05:20 by mvavasso         ###   ########.fr       */
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
};

#endif