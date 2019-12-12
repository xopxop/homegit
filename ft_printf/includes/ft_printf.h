/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:45:44 by dthan             #+#    #+#             */
/*   Updated: 2019/12/07 05:34:01 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"
# include "info.h"

int	ft_printf(char *format, ...); //need to change back to const char

// HELPER_FT
int	get_nbr(char *format, int pos);

// IDENTIFIER_FT
int     is_flags(char *format, t_info *info, int pos);
int    is_width(char *format, t_info *info, int pos);
int	is_percision(char *format, t_info *info, int pos);
int	is_specifier(char *format, t_info *info, int pos);

// PARSING FT
int	parse_and_print(va_list arg, char *format, int pos);

//PRINTING.C
void	printing_helper(t_info *info, va_list arg);

#endif
