/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 05:43:01 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 08:35:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULT_TERMINATOR_HPP
# define ASSAULT_TERMINATOR_HPP
# include "ISpaceMarine.hpp"
# include <string>
# include <iostream>

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const & src);
		~AssaultTerminator(void);
		AssaultTerminator & operator = (AssaultTerminator const & rhs);

		ISpaceMarine*	clone(void)			const;
		void			battleCry(void)		const;
		void			rangedAttack(void)	const;
		void			meleeAttack(void)	const;
};

std::ostream & operator << (std::ostream & o, AssaultTerminator const & i);

#endif
