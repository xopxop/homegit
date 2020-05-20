/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 01:27:52 by dthan             #+#    #+#             */
/*   Updated: 2020/05/13 01:27:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) : _foo( 0 ) {
    std::cout << "Default Constructor called" << std::endl;
    return ;
}

Sample::Sample( int const n ) : _foo( n ) {
    std::cout << "Parametric Constructor called" << std::endl;
    return ;
}

Sample::Sample( Sample const & src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Sample::~Sample( void ) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

int    Sample::getFoo( void ) const {
    return this->_foo;
}

Sample &    Sample::operator=( Sample const & rhs ) {
    std::cout << "Assignment operator called" << std::endl;
    
    if ( this != &rhs )
        this->_foo = rhs.getFoo();
    return *this;
}

std::ostream &  operator<< ( std::ostream & o, Sample const & rhs ) {
    o << "The value of _foo is : " << rhs.getFoo();
    return o;
}
