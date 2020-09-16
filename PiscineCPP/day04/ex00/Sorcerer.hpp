/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 05:38:41 by dthan             #+#    #+#             */
/*   Updated: 2020/08/30 18:53:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <string>
# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
	private:
		std::string _name;
		std::string _title;

	public:
		Sorcerer(void);
		Sorcerer(Sorcerer const & src);
		Sorcerer(std::string name, std::string title);
		~Sorcerer(void);
		Sorcerer & operator = (Sorcerer const & rhs);

		std::string getName(void) const;
		std::string getTitle(void) const;

		void polymorph(Victim const & target) const;
};

std::ostream & operator << (std::ostream & output, const Sorcerer & input);

#endif
