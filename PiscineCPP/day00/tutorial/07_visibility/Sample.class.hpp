/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:17:05 by dthan             #+#    #+#             */
/*   Updated: 2020/04/13 14:17:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SIMPLE_CLASS_H

class Sample {
	public:
		int publicFoo;
		Sample(void);
		~Sample(void);

		void publicBar(void) const;

	private:
		int		_privateFoo;
		
		void	_privateBar(void) const;
};

#endif
