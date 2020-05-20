/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:20:42 by dthan             #+#    #+#             */
/*   Updated: 2020/05/13 16:20:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.class.hpp"

Fixed::Fixed( void ) : _fixedPointValue( 0 ) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed( int  const value ) {
    std::cout << "Int constructor called" << std::endl;
    setRawBits(roundf( value << this->_fractionalBits ));
    return ;
}

Fixed::Fixed( float const value ) {
    std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf( value * (1 << this->_fractionalBits )));
    return ;
}

Fixed::Fixed( Fixed const & src ) {
    std::cout << "Coppy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

float   Fixed::toFloat( void ) const {
    return ((float)getRawBits() / ( 1 << this->_fractionalBits));
}

int Fixed::toInt( void ) const {
    return (getRawBits() >> this->_fractionalBits);
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
    std::cout << "Assignation operator called" << std::endl;
    if ( this != &rhs )
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

int     Fixed::getRawBits( void ) const {
    return this->_fixedPointValue;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}

std::ostream &  operator<< ( std::ostream & o, Fixed const & rhs ) {
    o << rhs.toFloat();
    return o;
}