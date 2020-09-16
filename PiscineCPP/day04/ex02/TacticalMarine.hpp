/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 05:24:55 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 07:51:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP
# include "ISpaceMarine.hpp"
# include <string>
# include <iostream>

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine(void);
		TacticalMarine(TacticalMarine const & src);
		~TacticalMarine(void);
		TacticalMarine & operator = (TacticalMarine const & rhs);

		ISpaceMarine*	clone(void)			const;
		void			battleCry(void)		const;
		void			rangedAttack(void)	const;
		void			meleeAttack(void)	const;
};

std::ostream & operator << (std::ostream & o, TacticalMarine const & i);

#endif
