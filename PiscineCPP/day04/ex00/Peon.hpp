/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:46:05 by dthan             #+#    #+#             */
/*   Updated: 2020/08/30 19:18:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP
# include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(void);
		Peon(std::string name);
		Peon(Peon const & src);
		~Peon(void);
		Peon & operator = (Peon const & rhs);

		virtual void getPolymorphed(void) const;
};

#endif
