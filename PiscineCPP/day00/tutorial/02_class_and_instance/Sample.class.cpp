/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 14:54:00 by dthan             #+#    #+#             */
/*   Updated: 2020/04/12 14:54:03 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) {
	std::cout << "Construct called" << std::endl;
	return ;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}