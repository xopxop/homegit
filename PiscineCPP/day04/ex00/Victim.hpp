/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:23:39 by dthan             #+#    #+#             */
/*   Updated: 2020/08/30 19:18:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <string>
# include <iostream>

class Victim
{
	protected:
		std::string _name;

	public:
		Victim(void);
		Victim(Victim const & src);
		Victim(std::string name);
		~Victim(void);
		Victim & operator = (Victim const & rhs);

		std::string getName(void) const;

		virtual void getPolymorphed(void) const;
};

std::ostream & operator << (std::ostream & output, const Victim & input);

#endif
