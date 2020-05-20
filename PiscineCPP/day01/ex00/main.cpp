/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:59:25 by dthan             #+#    #+#             */
/*   Updated: 2020/05/01 00:59:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void    ponyOnTheStack(void) {
    Pony    pony = Pony("Mr.White", 2, "black");

    std::cout << pony.getNickname() << " is " << pony.getAge() << " and he is "
    << pony.getColor() << std::endl;
}

void    ponyOnTheHeap(void) {
    Pony*   pony = new Pony("Mr.Black", 5, "white");

    std::cout << pony->getNickname() << " is " << pony->getAge() << " and he is "
    << pony->getColor() << std::endl;
    delete pony;
}

int main () {
    ponyOnTheHeap();
    ponyOnTheStack();
    return (0);
}
