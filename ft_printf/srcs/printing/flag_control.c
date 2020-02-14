/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:36:35 by dthan             #+#    #+#             */
/*   Updated: 2020/02/13 18:41:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void zero_flag(t_info *info, char **str, int negative)
{
	int position;

	if (info->flags & ZERO)
	{
		position = 0;
		while (**str != ' ')
			position++;
		ft_memset(*str, '0', position);
		if (negative)
			*str[0] = '-';
	}
}

void space_flag(t_info *info, char **str, int negative)
{
	if (info->flags & SPACE)
	{
		if (!negative)
			*str = ft_strjoin_and_free_string2("0", *str);
		else
			*str[0] = ' ';
	}
}

void plus_flag(t_info *info, char **str, int negative)
{
	if (info->flags & SPACE)
	{
		if (!negative)
			*str = ft_strjoin_and_free_string2("0", *str);
		else
			*str[0] = ' ';
	}
}

void hash_flag(t_info *info, char **str)
{
	if (info->flags & HASH_SIGN)
	{

	}
}

void	flag_control(t_info *info, char **str)
{
	int negative;

	negative = 0;
	while (*str)
		if (**str == '-')
		{
			negative = 1;
			**str = ' ';
			break ;
		}
	zero_flag(info, str, negative);
	if (!negative || !(info->specifier == spec_octal && info->specifier == spec_hexlowcase && info->specifier == spec_hexupcase))
	{
		space_flag(info, str, negative);
		plus_flag(info, str, negative);
	}
	hash_flag(info, str);
}

void flag_ignore(t_info *info)
{
	if ((info->percision > -1 || info->flags & MINUS_SIGN) && info->flags & ZERO)
		info->flags ^= ZERO;
	if (info->flags & PLUS_SIGN && info->flags & ZERO)
		info->flags ^= SPACE;
	if (info->flags & HASH_SIGN && (info->specifier == spec_int || info->specifier == spec_uint))
		info->flags ^= HASH_SIGN;
}

/*
void	flag_control(t_info *info, char **str)
{
	if (info->percision > -1 && info->flags & ZERO)
		info->flags ^= ZERO;
	if (info->specifier == spec_hexlowcase || info->specifier == spec_hexupcase\
			|| info->specifier == spec_octal)
	{
		if (info->percision == 0 && !ft_strcmp("0", *str) && \
					info->specifier == spec_octal)
			**str = '\0';
		if (info->flags & HASH_SIGN && !ft_strcmp("0", *str))
			info->flags ^= HASH_SIGN;
	}
	if (info->percision == 0 && !ft_strcmp("0", *str)\
			&& info->specifier != spec_octal && info->specifier != spec_float)
		**str = '\0';
	if ((info->flags & PLUS_SIGN || info->flags & SPACE) && *str[0] != '-' \
	&& !(info->specifier == spec_uint || info->specifier == spec_octal || \
	info->specifier == spec_hexlowcase || info->specifier == spec_hexupcase))
	{
		*str = ft_strjoin_and_free_string2((info->flags & SPACE) ? " " : "+", \
				*str);
		*str[0] = (info->flags & PLUS_SIGN) ? '+' : *str[0];
	}
}
*/

// Type o; no flags '+', ' ' ; flag '+' is ignored when there is ' ' ; flag '0' is ignored when flag '-' is present
// Type h; no flags '+', ' ' ; flag '+' is ignored when there is ' ' ; flag '0' is ignored when flag '-' is present
// Type_d, i; no flags '#'; flag '+' is ignored when there is ' ' ; flag '0' is ignored when flag '-' is present
// Type_u, no flags '+', ' ', '#'; flag '+' is ignored when there is ' ' ; flag '0' is ignored when flag '-' is present

// String
// Percision
// Field_Width
// FLAG