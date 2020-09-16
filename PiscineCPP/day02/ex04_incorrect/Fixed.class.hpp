/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:20:46 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 17:51:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
# include <string>

class Fixed {
    public:
        Fixed( void );
        Fixed( int );
        Fixed( float );
        Fixed( Fixed const & src );
        ~Fixed( void );

        float   toFloat( void ) const;
        int     toInt( void ) const;
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        
        Fixed & operator=( Fixed const & rhs );
        Fixed   operator+( Fixed const & rhs ) const;
        Fixed   operator-( Fixed const & rhs ) const;
        Fixed   operator*( Fixed const & rhs ) const;
        Fixed   operator/( Fixed const & rhs ) const;

        bool   operator>( Fixed const & rhs ) const;
        bool   operator<( Fixed const & rhs ) const;
        bool   operator>=( Fixed const & rhs ) const;
        bool   operator<=( Fixed const & rhs ) const;
        bool   operator==( Fixed const & rhs ) const;
        bool   operator!=( Fixed const & rhs ) const;

        Fixed & operator++( void );
        Fixed & operator--( void );

        Fixed   operator++( int );
        Fixed   operator--( int );

        static Fixed &  min( Fixed &, Fixed &);
        static Fixed const &    min( Fixed const &, Fixed const &);
        static Fixed &  max( Fixed &, Fixed &);
        static Fixed const &    max( Fixed const &, Fixed const &);

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & i);

#endif
