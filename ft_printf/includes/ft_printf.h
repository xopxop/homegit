/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:45:44 by dthan             #+#    #+#             */
/*   Updated: 2019/12/17 04:53:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

/*
** Flags uses a binary addressing system
** ZERO : pad with zero
** PLUS_SIGN : show plus
** SPACE : space if plus
** MINUS_SIGN : left justified
** HASH_SIGN : show 0x, etc.
*/

# define ZERO	1
# define PLUS_SIGN		2
# define SPACE		4
# define MINUS_SIGN		8
# define HASH_SIGN	16
# define SMALL 32
# define SIGN 64 /*unsigned/signed long*/

typedef enum e_specifier t_specifier;

enum	e_specifier
{
	spec_char,
	spec_str,
	spec_ptr,
	spec_int,
	spec_uint,
	spec_octal,
	spec_hexlowcase,
	spec_hexupcase,
	spec_float,
	spec_percentsign,
	spec_none,
};

typedef enum e_length t_length;

enum	e_length
{
	len_hh,
	len_h,
	len_ll,
	len_l,
	len_lup,
	len_none,
};

typedef unsigned char t_u8bits;
typedef unsigned short t_u16bits;
typedef unsigned int t_u32bits;
typedef unsigned long long t_u64bits;

typedef char t_8bits;
typedef short t_16bits;
typedef int	 t_32bits;
typedef long long t_64bits;

typedef struct		s_info
{

	int		flags;
	int		field_width;
	int		percision;
	t_length		length;
	t_specifier	specifier;
}t_info;

//CORE

int	ft_printf(char const *format, ...);
int full_str_printing(const char *format, va_list args, t_info *info);
int parse_and_print(const char *format, va_list args, size_t *pos, t_info *info);

// PARSING
void    parsing(const char *format, va_list args, size_t *pos, t_info *info);
void struct_init(t_info *info);

// PARSING/HELPER
int ft_skip_atoi(const char *format, size_t *pos);

// PARSING/FILL_STRUCT
void    get_flags(const char *format, size_t *pos, t_info *info);
void    get_field_width(const char *format, size_t *pos, va_list arg, t_info *info);
void    get_precision(const char *format, size_t *pos, va_list arg, t_info *info);
void    get_length(const char *format, size_t *pos, t_info *info);
void    get_specifier(const char *format, size_t *pos, t_info *info);

// PRINTING
int	printing(t_info *info, va_list arg);

// TYPE_C
void type_c(t_info *info, va_list arg, char **output);
void type_s(t_info *info, va_list arg, char **output);
void type_p(t_info *info, va_list arg, char **output);
void type_di(t_info *info, va_list arg, char **output);
void type_u(t_info *info, va_list arg, char **output);
void type_o(t_info *info, va_list arg, char **output);
void type_x(t_info *info, va_list arg, char **output);
void type_x_up(t_info *info, va_list arg, char **output);
void type_f(t_info *info, va_list arg, char **output);

// PRINTING/PRINTING HELPER
long long get_signed_argument(t_info* info, va_list arg);
unsigned long long get_unsigned_argument(t_info* info, va_list arg);
char *ft_number_conversion(unsigned long long num, int mask, int shiff_nbr, int strlen, char *s);
char *ft_strrev(char *s);
void ft_right_just(t_info *info, char **str, char *new);
void ft_pad_handle(t_info *info, char **str);
void    ft_prec_nums(t_info *info, char **str);
void ft_prec_handle(t_info *info, char **str);

//char    *type_o(t_info *info, va_list arg);
//char    *type_h(t_info *info, va_list arg);

#endif
