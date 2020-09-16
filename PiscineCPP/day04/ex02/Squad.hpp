/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 05:10:43 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 08:36:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"
# include <iostream>

typedef struct			s_container
{
	ISpaceMarine*		unit;
	struct s_container*	next;
}						t_container;

class Squad : public ISquad
{
	private:
		t_container*			_squad;
		static int				_numberOfUnits;
	public:
		Squad(void);
		Squad(Squad const & src);
		~Squad(void);
		Squad & operator = (Squad const & rhs);

		int				getCount(void)	const;
		ISpaceMarine*	getUnit(int)	const;
		int push(ISpaceMarine*);
};

#endif
