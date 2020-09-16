/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:53:40 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 17:54:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & src);
		Ice & operator = (Ice const & rhs);
		~Ice(void);
		
		AMateria*	clone(void) const;
		void		use(ICharacter & target);
};

#endif