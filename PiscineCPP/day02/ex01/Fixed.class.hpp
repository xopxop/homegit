/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:20:46 by dthan             #+#    #+#             */
/*   Updated: 2020/05/13 16:20:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {
    public:
        Fixed( void );
        Fixed( int );
        Fixed( float );
        Fixed( Fixed const & src );
        ~Fixed( void );
        float   toFloat( void ) const;
        int     toInt( void ) const;
        Fixed & operator=( Fixed const & rhs );
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & i);

#endif
