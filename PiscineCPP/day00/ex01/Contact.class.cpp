/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:01:38 by dthan             #+#    #+#             */
/*   Updated: 2020/04/23 11:01:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}

std::string Contact::getLastName(void) const {
	return this->_lastName;
}

std::string Contact::getNickname(void) const {
	return this->_nickname;
}

std::string Contact::getLogin(void) const {
	return this->_login;
}

std::string Contact::getPostalAddress(void) const {
	return this->_postalAddress;
}

std::string Contact::getEmailAddress(void) const {
	return this->_emailAddress;
}

std::string Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

std::string Contact::getFavoriteMeal(void) const {
	return this->_favoriteMeal;
}

std::string Contact::getUnderwearColor(void) const {
	return this->_underwearColor;
}

std::string Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}

void Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
	return ;
}

void Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
	return ;
}

void Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
	return ;
}

void Contact::setLogin(std::string login) {
	this->_login = login;
	return ;
}

void Contact::setPostalAddress(std::string postalAddress) {
	this->_postalAddress = postalAddress;
	return ;
}
void Contact::setEmailAddress(std::string emailAddress) {
	this->_emailAddress = emailAddress;
	return ;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
	return ;
}

void Contact::setBirthdayDate(std::string birthdayDate) {
	this->_birthdayDate = birthdayDate;
	return ;
}

void Contact::setFavoriteMeal(std::string favoriteMeal) {
	this->_favoriteMeal = favoriteMeal;
	return ;
}

void Contact::setUnderwearColor(std::string underwearColor) {
	this->_underwearColor = underwearColor;
	return ;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
	return ;
}
