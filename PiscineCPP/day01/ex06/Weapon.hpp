/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 12:45:44 by dthan             #+#    #+#             */
/*   Updated: 2020/05/10 12:45:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string&	getType(void);
		void			setType(std::string type);

	private:
		std::string _type;
};

#endif
