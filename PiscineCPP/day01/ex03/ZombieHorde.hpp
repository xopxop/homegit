/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 08:54:51 by dthan             #+#    #+#             */
/*   Updated: 2020/05/08 08:54:52 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP
# include "Zombie.hpp"

class ZombieHorde{
    public:
		ZombieHorde(int num);
		~ZombieHorde();
		Zombie*		horde;
		void 		announce();
		int			num;
		std::string	randomName(void);
		std::string	randomType(void);
};

#endif
