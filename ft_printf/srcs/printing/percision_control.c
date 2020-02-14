/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:46:54 by dthan             #+#    #+#             */
/*   Updated: 2020/02/10 08:39:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** This function prec_ctrl_str is using for type s and type p
** when there is no precision, printing normal string
** if there is precision, then the string will be null-terminated at
** the precision number (only string's length is smaller than the percision)
*/

void	prec_ctrl_str(t_info *info, char **str)
{
	if (info->percision < 0)
		return ;
	if (ft_strlen(*str) <= (size_t)info->percision)
		return ;
	(*str)[info->percision] = '\0';
}

/*
** This prec_ctrl_nums is using for type_di and type_u
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

void	prec_ctrl_nums(t_info *info, char **str)
{
	char *new;
	char extra;
	char *orig;

	orig = *str;
	if (!**str)
		return ;
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
** This prec_ctrl_oct_hex is using for type_octal and type_hexadicimal
*/

void	prec_ctrl_oct_hex(t_info *info, char **str, char *hash_str)
{
	char	*new;
	int		hash;

	hash = 0;
	if (info->percision < (int)ft_strlen(*str))
		info->percision = (int)ft_strlen(*str);
	if (info->flags & HASH_SIGN)
		hash = (info->specifier == spec_hexlowcase || \
		info->specifier == spec_hexupcase) ? 2 : 1;
	new = ft_strnew(info->percision + hash);
	ft_memset(new + hash, '0', info->percision - ft_strlen(*str));
	ft_strcpy(new + hash + info->percision - ft_strlen(*str), *str);
	if (hash)
		ft_strncpy(new, hash_str, hash);
	free(*str);
	*str = new;
}
