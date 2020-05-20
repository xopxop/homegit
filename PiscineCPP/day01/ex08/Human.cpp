/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:52:39 by dthan             #+#    #+#             */
/*   Updated: 2020/05/11 00:52:39 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void    Human::action(std::string const & action_name, std::string const & target) {
    void (Human::*ptr[])(std::string const & target) =
    {
        &Human::meleeAttack,
        &Human::rangedAttack,
        &Human::intimidatingShout,
    };

    std::string command[] =
    {
        "meleeAttack",
        "rangedAttack",
        "intimidatingShout"
    };

    for (int i = 0; i < 3; i++) {
        if (command[i] == action_name) {
            (this->*ptr[i])(target);
            break;
        }
    }
}

void    Human::meleeAttack(std::string const & target) {
    std::cout << "Using melee-attack to " << target << std::endl;
}

void    Human::rangedAttack(std::string const & target) {
    std::cout << "Using ranged-attack to " << target << std::endl;
}

void    Human::intimidatingShout(std::string const & target) {
    std::cout << "Using intimidating shout to " << target << std::endl;
}
