/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:12:52 by dthan             #+#    #+#             */
/*   Updated: 2020/04/22 14:12:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

void	f0(void) {

	Sample instance;

	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;

	return ;
}

void	f1(void) {

	Sample instance;

	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;
	f0();

	return ;
}

int main() {

	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;

	return 0;
}
