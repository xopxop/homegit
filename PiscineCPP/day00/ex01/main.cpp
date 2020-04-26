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

#include "phoneBook.hpp"

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
	phoneBook->setPhoneNumber(answer);
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
	std::cout << std::endl;
}

void getContact(Contact phoneBook[], int len) {
	int inputIndex;

	std::cout << "What index entry you want to search?" << std::endl;
	std::cin >> inputIndex;
	if (inputIndex < 1 && inputIndex >= len)
		std::cout << "Index entry is invalid." << std::endl;
	else {
		std::cout << phoneBook[inputIndex - 1].getFirstName() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getLastName() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getNickname() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getLogin() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getPostalAddress() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getEmailAddress() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getPhoneNumber() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getBirthdayDate() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getFavoriteMeal() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getUnderwearColor() << std::endl;
		std::cout << phoneBook[inputIndex - 1].getDarkestSecret() << std::endl;
	}
	std::cin.ignore(INT_MAX, '\n');
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
	if (len > 0)
		getContact(phoneBook, len);
	else
		std::cout << "Empty Phonebook!" << std::endl;
	std::cout << std::endl;
}

int main(void) {
	Contact phoneBook[8];
	std::string command;
	int i;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	i = 0;
	while(true) {
		std::cout << "Please enter: ADD for adding new contact, SEARCH for searching and EXIT for get out of the program:" << std::endl;
		std::getline (std::cin, command, '\n');
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
	std::cout << "Bye!" << std::endl;
	return (EXIT_SUCCESS);
}
