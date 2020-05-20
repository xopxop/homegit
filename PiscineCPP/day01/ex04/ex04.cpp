/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 05:28:15 by dthan             #+#    #+#             */
/*   Updated: 2020/05/10 05:28:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
    std::string     str = "HI THIS IS BRAIN";
    std::string*    ptrStr = &str;
    std::string&    refStr = str;

    std::cout << "ptrStr = "<< *ptrStr << std::endl;
    std::cout << "refStr = " << refStr << std::endl;

    return (EXIT_SUCCESS);
}
