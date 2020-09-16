/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:42:17 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 17:50:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_HPP
# define EVAL_EXPR_HPP
# include "Fixed.class.hpp"
# include <iostream>
# include <sstream>
# include <string>

float parseNumber(std::string s, size_t & i);
Fixed parseFixedNumber(std::string s, size_t & i);
Fixed parseMultiplicative(std::string s, size_t & i);
Fixed eval_expr(std::string s, size_t & i);

#endif