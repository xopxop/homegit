/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:52:43 by dthan             #+#    #+#             */
/*   Updated: 2020/05/11 00:52:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_CLASS_HPP
# define HUMAN_CLASS_HPP
# include <iostream>
# include <string>

class Human {
    public:
        void    action(std::string const & action_name, std::string const & target);

    private:
        void    meleeAttack(std::string const & target);
        void    rangedAttack(std::string const & target);
        void    intimidatingShout(std::string const & target);
};

#endif
