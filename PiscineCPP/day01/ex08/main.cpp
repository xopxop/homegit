/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:52:34 by dthan             #+#    #+#             */
/*   Updated: 2020/05/11 00:52:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void) {
    Human Human;

    Human.action("meleeAttack", "a bat");
    Human.action("rangedAttack", "a mouse");
    Human.action("intimidatingShout", "an ape");
    return (EXIT_SUCCESS);
}
