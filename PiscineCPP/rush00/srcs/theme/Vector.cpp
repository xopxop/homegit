/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:11:02 by dthan             #+#    #+#             */
/*   Updated: 2020/09/02 17:31:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Vector.hpp"

Vector::Vector(void) { }

Vector::Vector(unsigned int y, unsigned int x) {
	this->_y = y;
	this->_x = x;
}

Vector::Vector(const Vector & src) {
	*this = src;
}

Vector::~Vector(void) {
	// sth here
}

Vector & Vector::operator=(const Vector & src) {
	if (this != &src) {
		this->_y = src.getY();
		this->_x = src.getX();
	}
	return *this;
}

unsigned int Vector::getY(void) const {
	return this->_y;
}

unsigned int Vector::getX(void) const {
	return this->_x;
}
