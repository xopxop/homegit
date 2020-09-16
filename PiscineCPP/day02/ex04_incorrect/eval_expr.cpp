/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:41:28 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 18:14:55 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

float parseNumber(std::string s, size_t & i)
{
	std::istringstream inStrstream;
	float val;
	float sign;

	sign = (s[i] == '-') ? -1 : 1;
	i += (s[i] == '-' || s[i] == '+') ? 1 : 0;

	inStrstream.str(s.substr(i));
	inStrstream >> val;

	while (std::string("0123456789.").find(s[i]) != std::string::npos)
		i++;

	return (val * sign);
}

Fixed parseFixedNumber(std::string s, size_t & i)
{
	Fixed number;

	while (s[i]) {
		if (s[i] == '(') {
			return (eval_expr(s, ++i));
		} else if (std::string("+-0123456789").find(s[i]) != std::string::npos) {
			return (Fixed(parseNumber(s, i)));
		} else {
			i++;
		}
	}
	return (number);
}

Fixed parseMultiplicative(std::string s, size_t & i)
{
	Fixed lhs;

	lhs = parseFixedNumber(s, i);
	while (s[i]) {
		if (s[i] == '*') {
			lhs = lhs * parseFixedNumber(s, ++i);
		}
		else if (s[i] == '/') {
			lhs = lhs / parseFixedNumber(s, ++i);
		}
		else if (s[i] == ' ') {
			i++;
		}
		else {
			break;
		}
	}
	return (lhs);
}

Fixed eval_expr(std::string s, size_t & i)
{
	Fixed lhs;
	lhs = parseMultiplicative(s, i);
	while (s[i]) {
		if (s[i] == ')') {
			i++;
			break;
		} else if (s[i] == '+') {
			lhs = lhs + parseMultiplicative(s, ++i);
		} else if (s[i] == '-') {
			lhs = lhs - parseMultiplicative(s, ++i);
		} else if (s[i] == ' ') {
			i++;
		} else {
			break;
		}
	}
	return (lhs);
}
