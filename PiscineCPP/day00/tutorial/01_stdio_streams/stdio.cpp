/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 14:43:16 by dthan             #+#    #+#             */
/*   Updated: 2020/04/12 14:45:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	char buf[512];

	std::cout << "Hello world !" << std::endl;
	std::cout << "Input a word: ";
	std::cin >> buf;
	std::cout << "You entered: [" << buf << "]" << std::endl;
	return (0);
}
