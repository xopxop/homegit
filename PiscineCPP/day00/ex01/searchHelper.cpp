/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchHelper.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:20:33 by dthan             #+#    #+#             */
/*   Updated: 2020/04/26 12:20:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

static std::string truncatedStr(std::string str) {
	std::string truncated;

	truncated.assign(str, 0, 9);
	truncated.append(1, '.');
	return (truncated);
}

static std::string extraSpace(std::string str) {
	std::string newStr;

	newStr.append(10 - str.length(), ' ');
	newStr.append(str);
	return (newStr);
}

std::string fittedStr(std::string str) {
	if (str.length() > 10)
		return (truncatedStr(str));
	else if (str.length() < 10)
		return (extraSpace(str));
	return (str);
}
