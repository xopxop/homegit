/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:27:52 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 03:26:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_CLASS_HPP
# define INTEGER_CLASS_HPP

# include <iostream>

class Integer {
    public:
        Integer( int const n );
        ~Integer( void );

        int         getValue( void ) const;

        Integer &   operator=( Integer const & rhs );
		Integer     operator+( Integer const & rhs ) const;

    private:
        int     _n;
};

std::ostream & operator<<( std::ostream & o, Integer const & rhs);

#endif
