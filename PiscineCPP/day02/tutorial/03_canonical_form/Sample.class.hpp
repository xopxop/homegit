/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 01:22:26 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 03:49:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

# include <iostream>

class Sample {
    public:
        Sample( void );             // Canonical
        Sample( int const n );
        Sample( Sample const & src );    // Canonical
        ~Sample(void);						//Canonical

        Sample &    operator=( Sample const & rhs );    // Canonical

        int         getFoo( void ) const;

    private:
        int         _foo;
};


std::ostream &      operator<<( std::ostream & o, Sample const & i );

#endif
