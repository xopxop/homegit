/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:02:17 by dthan             #+#    #+#             */
/*   Updated: 2020/09/02 17:31:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

class Vector
{
	private:
		unsigned int _y;
		unsigned int _x;
	public:
		Vector(void);
		Vector(unsigned int, unsigned int);
		Vector(const Vector &);
		~Vector(void);
		Vector & operator=(const Vector &);

		unsigned int getY(void) const;
		unsigned int getX(void) const;
};

#endif
