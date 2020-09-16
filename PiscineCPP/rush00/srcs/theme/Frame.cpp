/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:32:21 by dthan             #+#    #+#             */
/*   Updated: 2020/09/02 17:34:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Frame.hpp"

Frame::Frame(void) { }

Frame::Frame(Vector offset, Vector bounds) {
	this->_offset = offset;
	this->_bounds = bounds;
}


