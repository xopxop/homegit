/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:59:21 by dthan             #+#    #+#             */
/*   Updated: 2020/05/01 00:59:22 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H
# include <iostream>

class Pony
{
	public:
		Pony(std::string, unsigned int, std::string);
		~Pony(void);
		std::string getNickname(void) const;
		int			getAge(void) const;
		std::string getColor(void) const;
	
	private:
		std::string _nickname;
		int			_age;
		std::string _color;
};

#endif
