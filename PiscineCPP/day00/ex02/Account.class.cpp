/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 01:33:00 by dthan             #+#    #+#             */
/*   Updated: 2020/04/30 01:33:03 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.class.hpp"
#define BLUE    "\033[34m" 
#define RESET   "\033[0m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
	time_t currentTime = time(NULL);
	struct  tm *stamp = localtime(&currentTime);

	std::cout << "[" << (1900 + stamp->tm_year);
	if (stamp->tm_mon < 10)
		std::cout << "0" << stamp->tm_mon;
	else
		std::cout << stamp->tm_mon;
	if (stamp->tm_mday < 10)
		std::cout << "0" << stamp->tm_mday;
	else
		std::cout << stamp->tm_mday;
	std::cout << "_";
	if (stamp->tm_hour < 10)
		std::cout << "0" << stamp->tm_hour;
	else
		std::cout << stamp->tm_hour;
	if (stamp->tm_min < 10)
		std::cout << "0" << stamp->tm_min;
	else
		std::cout << stamp->tm_min;
	if (stamp->tm_sec < 10)
		std::cout << "0" << stamp->tm_sec;
	else
		std::cout << stamp->tm_sec;
	std::cout << "] ";
}

Account::Account( int initial_depesit ) {
	_nbAccounts++;
	_totalAmount += initial_depesit;
	this->_accountIndex = this->_nbAccounts - 1;
	this->_amount = initial_depesit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "created" << std::endl;

	return ;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "closed" << std::endl;

	return ;
}

int  Account::getNbAccounts( void ) {
    return (_nbAccounts);
}

int  Account::getTotalAmount( void ) {
    return (_totalAmount);
}

int  Account::getNbDeposits( void ) {
    return (_totalNbDeposits);
}

int  Account::getNbWithdrawals( void ) {
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << BLUE << getNbAccounts() << RESET << ";";
	std::cout << "total:" << BLUE<< getTotalAmount() << RESET << ";";
	std::cout << "deposits:" << BLUE << getNbDeposits() << RESET << ";";
	std::cout << "withdrawals:" << BLUE << getNbWithdrawals() << RESET << std::endl;
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
    std::cout << "p_amount:" << BLUE << this->_amount << RESET << ";";
    std::cout << "deposit:" << BLUE << deposit << RESET << ";";
    std::cout << "amount:" << BLUE << (this->_amount += deposit) << RESET << ";";
	std::cout << "nb_deposits:" << BLUE << ++this->_nbDeposits << RESET << std::endl;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "p_amount:" << BLUE << this->_amount << RESET << ";";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << BLUE << withdrawal << RESET << ";";
	std::cout << "amount:" << BLUE << (this->_amount -= withdrawal) << RESET << ";";
	std::cout << "nb_withdrawals:" << BLUE << ++this->_nbWithdrawals << RESET << std::endl;
	_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "deposits:" << BLUE << this->_nbDeposits << RESET << ";";
	std::cout << "withdrawals:" << BLUE << this->_nbWithdrawals << RESET << std::endl;
}
