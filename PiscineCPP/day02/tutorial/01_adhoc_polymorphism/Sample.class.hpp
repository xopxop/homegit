/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:10:26 by dthan             #+#    #+#             */
/*   Updated: 2020/05/12 23:10:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {
    public:
        Sample( void );
        ~Sample( void );

        void bar( char const c ) const;
        void bar( int const n) const;
        void bar( float const z) const;
        void bar( Sample const & i ) const;
};

#endif
