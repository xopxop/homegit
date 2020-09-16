/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:30:33 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 17:49:22 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & src);
		Cure & operator = (Cure const & rhs);
		~Cure(void);
		
		AMateria*	clone(void) const;
		void		use(ICharacter & target);
};

#endif
