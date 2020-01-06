/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:46:54 by dthan             #+#    #+#             */
/*   Updated: 2020/01/06 21:02:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** This function ft_prec_handle is using for type s only
** when there is no precision, printing normal string
** if there is precision, then the string will be null-terminated at
** the precision number (only string's length is smaller than the percision)
*/

void	ft_prec_handle(t_info *info, char **str)
{
	if (info->percision == -1)
		return ;
	if (ft_strlen(*str) <= (size_t)info->percision)
		return ;
	(*str)[info->percision] = '\0';
}

/*
** This ft_prec_nums is using for type_di and type_u
** This ft will create a string and return it back
** Note:if the percision == 0 and the number is 0 -> nothing to be printed
**      if percision < strlen ->no percision (if no percision -> automaticly
**                                              make percision == 1)
** For normal number:
** -Firstly, check the sign of the string to check if the new string need one
** more space or not, if there is sign then the first position at the new string
** will be reserve for the sign ('-' || '+' || ' ', remember if there are plus
** and space flags then plus will be always be printed not space), move the the
** next position of the string
** -Secondly, filling the '0' with n time
** -Finally, filling the digit from the string to new string
*/

void	ft_prec_nums(t_info *info, char **str)
{
	char *new;
	char extra;
	char *orig;

	orig = *str;
	if (!**str)
		return ;
// 	if ((info->percision == 0 || info->percision == -1) && !ft_strcmp("0", *str) && (info->specifier == spec_int ||
//	 info->specifier == spec_octal || info->specifier == spec_hexlowcase))
//	{
//		**str = '\0';
//		return ;
//	}
	if (info->percision == -1)
		info->percision = 1;
	if (info->percision < (int)ft_strlen(*str))
		return ;
	extra = (!ft_isdigit((*str)[0])) ? (*str)[0] : 0;
	if (extra)
		(*str)++;
	new = ft_strnew(info->percision + !!extra);
	ft_memset(new + !!extra, '0', info->percision - ft_strlen(*str));
	ft_strcpy(new + info->percision - ft_strlen(*str) + !!extra, *str);
	if (extra)
		new[0] = extra;
	free(orig);
	*str = new;
}

/*
** NEED TO ADD COMMEND AND CHANGE NAME
*/

void	ft_percision_hex(t_info *info, char **str)
{
	char *origin;
	char *new;
	char extra;

	origin = *str;
	if (info->percision <= (int)ft_strlen(origin))
	{
		ft_percisionSmallerThanSTRLEN(info, str);
		return ;
	}
	extra = ((info->flags & PLUS_SIGN) || (info->flags & SPACE)) ? \
		((info->flags & PLUS_SIGN) ? '+' : ' ') : 0;
	new = ft_strnew(info->percision + 2 + !!extra);
	ft_memset(new + !!extra + 2, '0', info->percision - ft_strlen(*str));
	ft_strcpy(new + !!extra + 2 + info->percision - ft_strlen(*str), *str);
	if (extra)
		new[0] = extra;
	ft_strncpy(new + !!extra, "0x", 2);
	free(origin);
	*str = new;
}

// NEED TO ADD COMMEND AND CHANGE NAME

void	ft_percisionSmallerThanSTRLEN(t_info *info, char **str)
{
	char *origin;
	char *new;
	char extra;

	origin = *str;
	extra = ((info->flags & PLUS_SIGN) || (info->flags & SPACE)) ? \
		((info->flags & PLUS_SIGN) ? '+' : ' ') : 0;
	new = ft_strnew(ft_strlen(*str) + !!extra + 2);
	if (extra)
		new[0] = extra;
	ft_strncpy(new + !!extra, "0x", 2);
	ft_strcpy(new + !!extra + 2, *str);
	free(origin);
	*str = new;
}
