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

class Fixed {
    public:
        Fixed( void );
        Fixed( Fixed const & src );
        ~Fixed( void );

        Fixed & operator=( Fixed const & rhs );
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
};

#endif
