/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAsteroid.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 02:02:42 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 02:04:48 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_ASTEROID_HPP
# define INTERFACE_ASTEROID_HPP
# include <string>

class IAsteroid
{
	public:
		virtual ~IAsteroid() {}
		virtual std::string beMined([...] *) const = 0;
		[...]
		virtual std::string getName() const = 0;
};

#endif
