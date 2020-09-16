/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:21:00 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:48:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <string>

class Enemy
{
	protected:
		int			_hp;
		std::string _type;
	public:
		/* Coplien's form */
		Enemy(void);
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		virtual ~Enemy(void);
		Enemy & operator = (Enemy const & rhs);
		/* accessor */
		std::string getType(void) const;
		int			getHP(void) const;
		/* method */
		virtual void takeDamage(int);
};

#endif
