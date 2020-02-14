/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 15:03:31 by dthan             #+#    #+#             */
/*   Updated: 2020/01/06 21:01:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** pad_right is for padding to the left if there is no MINUS flag or with
** normal field_width applied
** - If there is flags ZERO -> fill with '0', it not fill with ' '
** - cp new string to the output string
*/

/*
void	pad_right(t_info *info, char **str, char *new)
{
	char extra;

	extra = 0;
	if (info->flags & ZERO)
	{
		extra = (!ft_isdigit((*str)[0]) && (info->specifier == spec_int \
				|| info->specifier == spec_float)) ? (*str)[0] : 0;
		ft_memset(new, '0', info->field_width - ft_strlen(*str) + \
				!!extra);
		if (extra)
		{
			new[0] = extra;
			(*str)[0] = '0';
		}
	}
	else
	{
		ft_memset(new, ' ', info->field_width - ft_strlen(*str));
		if ((info->flags & PLUS_SIGN) && **str != '-')
			new[info->field_width - ft_strlen(*str)] = ((*str)[0] ==\
					'-') ? '-' : '+';
	}
	ft_strcpy(new + info->field_width - ft_strlen(*str) + !!extra, *str \
			+ !!extra);
}
*/

/*
** This function width_ctrl will be used for padding, type d,i,u,c,s,f,p
** not using for type octal and hexadecimal
** if the field width is bigger than the strlength
** if MINUS flags, apply left justify
** else, right justification is the default
*/

void	width_ctrl(t_info *info, char **str)
{
	char *new;

	if (info->field_width == 0 || ft_strlen(*str) >= \
			(size_t)info->field_width)
		return ;
	new = ft_strnew(info->field_width);
	if (info->flags & MINUS_SIGN)
	{
		ft_strcpy(new, *str);
		ft_memset(new + ft_strlen(*str), ' ', info->field_width \
				- ft_strlen(*str));
	}
	else
	{
		ft_strcpy(new + ft_strlen(*str), *str);
		ft_memset(*str, ' ', info->field_width - ft_strlen(*str));
	}
	free(*str);
	*str = new;
	return ;
}

/*

void	width_ctrl(t_info *info, char **str)
{
	char *new;

	if (info->field_width == 0 || ft_strlen(*str) >= \
			(size_t)info->field_width)
		return ;
	new = ft_strnew(info->field_width);
	if (info->flags & MINUS_SIGN)
	{
		ft_strcpy(new, *str);
		ft_memset(new + ft_strlen(*str), ' ', info->field_width \
				- ft_strlen(*str));
	}
	else
		pad_right(info, str, new);
	free(*str);
	*str = new;
	return ;
}
*/

/*
** ---------------------HEXADECIMAL----------------------------
** This fuction is for right justificaion of the special case mentioned below
** Basically there will be a new string and it will be filled with this order
** filling 0x first, then filed the ZERO flags, then fill the string number
*/

void	ft_right_just_special_case(t_info *info, char **str, char *new)
{
	int		hash;
	char	extra;
	char	*temp;

	temp = *str;
	hash = (ft_strchr(*str, 'x')) ? 2 : 0;
	extra = (!ft_isalnum((*str)[0])) ? (*str)[0] : 0;
	if (hash)
		ft_strncpy(new, "0x", 2);
	ft_memset(new + hash, '0', info->field_width - ft_strlen(*str) + \
			!!extra);
	ft_strcpy(new + info->field_width - ft_strlen(*str) + !!extra + hash, \
			temp + !!extra + hash);
}

/*
** This special case is only for right justification to print 0x00000....
** Condition for this case there are field_width which are bigger than strlen,
** there are hash sign and zero flags, no minus flags
*/

void	ft_special_case(t_info *info, char **str)
{
	char *new;

	if ((info->field_width == 0 || ft_strlen(*str) < \
		(size_t)info->field_width) && (info->flags & HASH_SIGN) && \
			(info->flags & ZERO) && !(info->flags & MINUS_SIGN))
	{
		new = ft_strnew(info->field_width);
		ft_right_just_special_case(info, str, new);
		free(*str);
		*str = new;
	}
	else
		return ;
}
