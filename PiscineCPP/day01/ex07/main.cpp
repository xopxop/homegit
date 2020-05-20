/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 14:36:37 by dthan             #+#    #+#             */
/*   Updated: 2020/05/10 14:36:38 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void    replace2(std::string& data, std::string s1, std::string s2) {
    int a = (int) data.find(s1, 0);
    while (a != std::string::npos) {
        data.replace(a, s1.length(), s2);
        a = (int) data.find(s1, a + 1);
    }
}

void    replace(std::string fileName, std::string s1, std::string s2) {
    std::ifstream   ifs(fileName);
    std::string     line;
    std::string     data;

    if (ifs.is_open()) {
        std::ofstream   ofs(fileName + ".replace");
        if (ofs.is_open()) {
            while (getline(ifs, line))
                data += line + "\n";
            replace2(data, s1, s2);
            ofs << data;
        }
        else
            std::cout << "Error: Can not create the file" << std::endl;
    }
    else
        std::cout << "Error: Can not open the file" << std::endl;
}

int main (int ac, char **av) {
    if (ac != 4)
        std::cout << "HOW TO USE: ./replace [FILENAME] [WORD TO BE REPLACE] [WORD FOR REPLACE]" << std::endl;
    else {
        std::string av1 = av[1];
        std::string av2 = av[2];
        std::string av3 = av[3];
        if (av2.compare(av3) == 0)
            std::cout << "In valid input: [WORD TO BE REPLACE] = [WORD FOR REPLACE]" << std::endl;
        else
            replace(av1, av2, av3);
    }
    return (EXIT_SUCCESS);
}
