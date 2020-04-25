/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:03:08 by dthan             #+#    #+#             */
/*   Updated: 2020/04/22 22:03:09 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void megaphone(char **av) {
	for (int i = 0; av[i]; i++)
		for (int j = 0; av[i][j]; j++)
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				av[i][j] = av[i][j] - 32;
	for (int i = 0; av[i]; i++)
		std::cout << av[i];
	std::cout << std::endl;
}

int	main(int ac, char** av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBREARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
		megaphone(&av[1]);
	return (0);
}
