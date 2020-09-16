/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage1.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:18:37 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 18:38:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Otter {
	private:
		int	_numberOfLegs;

	public:
		Otter();
		Otter(Otter const &);
		Otter& operator=(Otter const &);
		~Otter();

		void run(int distance);

		void scornSomeone(std::string const & target);		
};

class Pony {
	private:
		int	_numberOfLegs;

	public:
		Pony();
		Pony(Pony const &);
		Pony& operator=(Pony const &);
		~Pony();

		void run(int distance);

		void doMagic(std::string const & target);
};
