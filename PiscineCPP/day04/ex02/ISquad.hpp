/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 05:11:31 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 08:25:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP
# include "ISpaceMarine.hpp"

class ISquad
{
	public:
		virtual ~ISquad() {}

		virtual int getCount() const = 0;
		virtual ISpaceMarine* getUnit(int) const = 0;

		virtual int push(ISpaceMarine*) = 0;
};

#endif
