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

int     Fixed::getRawBits( void ) const {
    return this->_fixedPointValue;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
    std::cout << "Assignation operator called" << std::endl;
    if ( this != &rhs )
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed   Fixed::operator+( Fixed const & rhs ) const {
    std::cout << "Addition operator called" << std::endl;
    return Fixed( this->_fixedPointValue + rhs.getRawBits());
}

Fixed   Fixed::operator-( Fixed const & rhs ) const {
    std::cout << "Subtraction operator called" << std::endl;
    return Fixed( this->_fixedPointValue - rhs.getRawBits());
}

Fixed   Fixed::operator*( Fixed const & rhs ) const {
    std::cout << "Muliplication operator called" << std::endl;
    return Fixed( this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/( Fixed const & rhs ) const {
    std::cout << "Division operator called" << std::endl;
    return Fixed( this->toFloat() / rhs.toFloat());
}

bool    Fixed::operator>( Fixed const & rhs ) const {
    std::cout << "Great comperation called" << std::endl;
    return (this->toFloat() > rhs.toFloat()) ? true : false;
}

bool    Fixed::operator<( Fixed const & rhs ) const {
    std::cout << "Less comperation called" << std::endl;
    return (this->toFloat() < rhs.toFloat()) ? true : false;
}

bool    Fixed::operator>=( Fixed const & rhs ) const {
    std::cout << "Great Equal comperation called" << std::endl;
    return (this->toFloat() >= rhs.toFloat()) ? true : false;
}

bool    Fixed::operator<=( Fixed const & rhs ) const {
    std::cout << "Less Equal comperation called" << std::endl;
    return (this->toFloat() <= rhs.toFloat()) ? true : false;
}

bool    Fixed::operator==( Fixed const & rhs ) const {
    std::cout << "Equal Equal comperation called" << std::endl;
    return (this->toFloat() == rhs.toFloat()) ? true : false;
}

bool    Fixed::operator!=( Fixed const & rhs ) const {
    std::cout << "Not Equal comperation called" << std::endl;
    return (this->toFloat() != rhs.toFloat()) ? true : false;
}

Fixed & Fixed::operator++( void ) {
    std::cout << "Pre-increment called" << std::endl;
    this->_fixedPointValue++;
    return *this;
}

Fixed & Fixed::operator--( void ) {
    std::cout << "Pre-decrement called" << std::endl;
    this->_fixedPointValue--;
    return *this;
}

Fixed   Fixed::operator++( int ) {
    std::cout << "Post-increment called" << std::endl;
    Fixed   tmp(*this);
    operator++();
    return tmp;
}

Fixed   Fixed::operator--( int ) {
    std::cout << "Post-decrement called" << std::endl;
    Fixed   tmp(*this);
    operator--();
    return tmp;
}

Fixed & Fixed::min( Fixed & lhs, Fixed & rhs ) {
    std::cout << "Min1 called" << std::endl;
    return (lhs.toFloat() < rhs.toFloat()) ? lhs : rhs;
}

Fixed const & Fixed::min( Fixed const & lhs, Fixed const & rhs ) {
    std::cout << "Min2 called" << std::endl;
    return (lhs.toFloat() < rhs.toFloat()) ? lhs : rhs;
}

Fixed & Fixed::max( Fixed & lhs, Fixed & rhs ) {
    std::cout << "Max1 called" << std::endl;
    return (lhs.toFloat() > rhs.toFloat()) ? lhs : rhs;
}

Fixed const & Fixed::max( Fixed const & lhs, Fixed const & rhs ) {
    std::cout << "Max2 called" << std::endl;
    return (lhs.toFloat() > rhs.toFloat()) ? lhs : rhs;
}

std::ostream &  operator<< ( std::ostream & o, Fixed const & rhs ) {
    o << rhs.toFloat();
    return o;
}
