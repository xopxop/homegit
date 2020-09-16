/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:22:09 by dthan             #+#    #+#             */
/*   Updated: 2020/09/02 17:01:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int init(void)
{
	srand(time(0));
	mainWnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	curs_set(0);
	start_color();
	
	return ;
}

void run(void)
{
	;
}

void close(void)
{
	;
}

int main(int ac, char **av) {
	int initStatus;

	if (ac == 1) {
		initStatus = init();
		if (initStatus == 0)
			run();
		close();
	} else
		printHelp();
	return 0;
}
