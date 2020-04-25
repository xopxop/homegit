/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 10:49:11 by dthan             #+#    #+#             */
/*   Updated: 2020/04/23 10:49:12 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

void add(Contact *phoneBook) {
	std::string answer;

	std::cout << "What is your First name?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setFirstName(answer);
	std::cout << "What is your Last name?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setLastName(answer);
	std::cout << "What is your Nick name?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setNickname(answer);
	std::cout << "What is your Login?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setLogin(answer);
	std::cout << "What is your Postal Address?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setPostalAddress(answer);
	std::cout << "What is your Email Address?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setEmailAddress(answer);
	std::cout << "What is your Phone Number?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setPostalAddress(answer);
	std::cout << "What is your Birhtday Date?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setBirthdayDate(answer);
	std::cout << "What is your Favorite Meal?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setFavoriteMeal(answer);
	std::cout << "What is your Underwear Color?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setUnderwearColor(answer);
	std::cout << "What is your Darkest Secret?" << std::endl;
	std::getline (std::cin, answer);
	phoneBook->setDarkestSecret(answer);
}

std::string truncatedStr(std::string str) {
	std::string truncated;

	truncated.assign(str, 0, 9);
	truncated.append(1, '.');
	return (truncated);
}

std::string extraSpace(std::string str) {
	std::string newStr;

	newStr.append(10 - str.length(), ' ');
	newStr.append(str);
	return (newStr);
}

std::string fittedStr(std::string str) {
	if (str.length() > 10)
		return (truncatedStr(str));
	else if (str.length() < 10)
		return (extraSpace(str));
	return (str);
}

void search(Contact phoneBook[], int len) {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < len; i++)
		std::cout << "|         " << i + 1 << "|" << \
		fittedStr(phoneBook[i].getFirstName()) << "|" << \
		fittedStr(phoneBook[i].getLastName()) << "|" << \
		fittedStr(phoneBook[i].getNickname()) << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

int main(void) {
	Contact phoneBook[8];
	std::string command;
	int i;

	i = 0;
	while(true) {
		std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
		std::cout << "Please enter: ADD for adding new contact, SEARCH for searching and EXIT for get out of the program:" << std::endl;
		std::getline (std::cin, command);
		if (command.compare("ADD") == 0)
			if (i < 8)
				add(&phoneBook[i++]);
			else
				std::cout << "Phonebook is full!" << std::endl;
		else if (command.compare("SEARCH") == 0)
			search(phoneBook, i);
		else if (command.compare("EXIT") == 0)
			break ;
	}
	return (EXIT_SUCCESS);
}
