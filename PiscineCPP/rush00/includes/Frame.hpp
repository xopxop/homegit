/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:37:19 by dthan             #+#    #+#             */
/*   Updated: 2020/09/02 17:34:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_HPP
# define FRAME_HPP
# include "Vector.hpp"

class Frame
{
	private:
		Vector _offset;
		Vector _bounds;
	public:
		Frame(void);
		Frame(Vector offset, Vector bounds);
		Frame(const Frame &);
		~Frame(void);
		Frame & operator=(const Frame &);

		unsigned int top(void);
		unsigned int bot(void);
		unsigned int left(void);
		unsigned int right(void);
		unsigned int width(void);
		unsigned int height(void);
		bool contains(Vector);
};

#endif
