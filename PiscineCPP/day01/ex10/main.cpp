/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 03:22:56 by dthan             #+#    #+#             */
/*   Updated: 2020/05/12 03:22:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void cat(char *file) {
    std::ifstream ifs(file);

    if(ifs.is_open())
        std::cout << ifs.rdbuf();
    else
        std::cout << "Error: Unable to open the file '" << file << "'" << std::endl;
}

int main(int ac, char **av) {
    if (ac == 1) // need to fix, it will read from the STDIN
        std::cout << "You need to feed me: ./a.out [FILENAME] ..." << std::endl;
    else {
        for (int i = 1; i < ac; i++)
            cat(av[i]);
    }    
}
