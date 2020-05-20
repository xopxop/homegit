/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:43:55 by dthan             #+#    #+#             */
/*   Updated: 2020/05/11 01:43:55 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Logger.hpp"

int main(int ac, char **av) {
    if (ac != 3)
        std::cout << "HOW TO USE: ./a.out [Console or File] [Message]" << std::endl;
    else {
        Logger log;
        std::string dest = av[1];
        std::string message = av[2];
        log.log(dest, message);
    }
    return (EXIT_SUCCESS);
}
