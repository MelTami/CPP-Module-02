/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:57:48 by mvavasso          #+#    #+#             */
/*   Updated: 2024/02/24 17:40:04 by mvavasso         ###   ########.fr       */
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
	Fixed( Fixed const &rhs );
	~Fixed();
    Fixed	            &operator=( Fixed const &fixed );
    int                 getRawBits( void ) const;
    void                setRawBits( int const raw );
};

#endif
