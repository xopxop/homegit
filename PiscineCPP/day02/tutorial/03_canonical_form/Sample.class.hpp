/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 01:22:26 by dthan             #+#    #+#             */
/*   Updated: 2020/05/13 01:22:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

# include <iostream>

class Sample {
    public:
        Sample( void );             // Connanical
        Sample( int const n );
        Sample( Sample const & src );    // Connanical
        ~Sample(void);

        Sample &    operator=( Sample const & rhs );    // Connanical

        int         getFoo( void ) const;

    private:
        int         _foo;
};


std::ostream &      operator<<( std::ostream & o, Sample const & i );

#endif
