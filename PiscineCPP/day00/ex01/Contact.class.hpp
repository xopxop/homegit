/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:01:24 by dthan             #+#    #+#             */
/*   Updated: 2020/04/23 11:01:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <iostream>
# include <string>
# include <iomanip>

class Contact {
	public:		
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getLogin(void) const;
		std::string getPostalAddress(void) const;
		std::string getEmailAddress(void) const;
		std::string getPhoneNumber(void) const;
		std::string getBirthdayDate(void) const;
		std::string getFavoriteMeal(void) const;
		std::string getUnderwearColor(void) const;
		std::string getDarkestSecret(void) const;

		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickname(std::string nickname);
		void setLogin(std::string login);
		void setPostalAddress(std::string postalAddress);
		void setEmailAddress(std::string emailAddress);
		void setPhoneNumber(std::string phoneNumber);
		void setBirthdayDate(std::string birthdayDate);
		void setFavoriteMeal(std::string favoriteMeal);
		void setUnderwearColor(std::string underwearColor);
		void setDarkestSecret(std::string darkestSecret);

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _login;
		std::string _postalAddress;
		std::string _emailAddress;
		std::string _phoneNumber;
		std::string _birthdayDate;
		std::string _favoriteMeal;
		std::string _underwearColor;
		std::string _darkestSecret;
};

#endif
