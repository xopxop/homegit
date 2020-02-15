/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 03:30:22 by dthan             #+#    #+#             */
/*   Updated: 2020/01/06 20:47:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** inilializing the struc info
*/

void	struct_init(t_info *info)
{
	info->flags = 0;
	info->field_width = 0;
	info->percision = -1;
	info->length = len_none;
	info->specifier = spec_none;
	info->dup_first_args = 0;
}

/*
** This parsing ft is not Fully well writen but it has the same concept (it
** needs to be put in a loop to check all the flags, width, length). However,
** it will initialize the struct then set all the value in the struct. After
** that it will start parsing flags, field_width, percision, length and
** specifier
*/

void	parsing(const char *format, va_list args, size_t *pos, t_info *info)
{
	struct_init(info);
	get_flags(format, pos, info);
	get_field_width(format, pos, args, info);
	get_precision(format, pos, args, info);
	get_length(format, pos, info);
	get_specifier(format, pos, info);
}
