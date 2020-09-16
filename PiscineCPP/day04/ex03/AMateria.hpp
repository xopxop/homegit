/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 16:54:40 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 01:33:52 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	private:
		std::string _type;
		unsigned int xp_;
	
	protected:
		AMateria(void);

	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		AMateria & operator = (AMateria const & rhs);
		~AMateria();

		void setXP(unsigned int);
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
