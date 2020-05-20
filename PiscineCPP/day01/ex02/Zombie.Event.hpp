/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zomebie.Event.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:34:16 by dthan             #+#    #+#             */
/*   Updated: 2020/05/02 16:34:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H
# include "Zombie.hpp"

class ZombieEvents {

	public:
		ZombieEvents(void);
		~ZombieEvents(void);
		Zombie* ptr;
		void    setZombieType(std::string);
		Zombie* newZombie(std::string);
		std::string	typez;
		Zombie* randomChump(void);
		void	killZombie(void);
};

#endif
