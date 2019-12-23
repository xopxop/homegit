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

# define STDOUT		1
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

# define SPECIFIER_COUNT 2 // Need to changed to 11(11 cases)

typedef enum e_specifier t_specifier;
typedef enum e_length t_length;

typedef unsigned char t_u8bits;
typedef unsigned short t_u16bits;
typedef unsigned int t_u32bits;
typedef unsigned long long t_u64bits;

typedef char t_8bits;
typedef short t_16bits;
typedef int	 t_32bits;
typedef long long t_64bits;


enum	e_length
{
	len_hh,
	len_h,
	len_ll,
	len_l,
	len_lup,
	len_none,
};

enum	e_specifier //Need to add more
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

typedef struct		s_info
{

	int		flags;
	int		field_width;
	int		percision;
	t_length		length;
	t_specifier	specifier;
}t_info;

/*
** ----------------------------Function dispatch Table------------------------
*/


//CORE

int	ft_printf(char const *format, ...);
int parse_and_print(const char *format, va_list args, t_info *info);

// HELPER
void struct_init(t_info *info);
int ft_skip_atoi(const char *format, size_t *pos);

// PARSING
void    parsing_flags(const char *format, size_t *pos, t_info *info);
void    get_field_width(const char *format, size_t *pos, va_list arg, t_info *info);
void    get_precision(const char *format, size_t *pos, va_list arg, t_info *info);
void    get_length(const char *format, size_t *pos, t_info *info);
void    parsing(const char *format, va_list args, size_t *pos, t_info *info);

// PRINTING
int	printing(t_info *info, va_list arg);

char *number(long num, int base, t_info *info);

// STR_SUMMARY
char    *type_c(t_info *info, va_list arg);
char    *type_s(t_info *info, va_list arg);
char    *type_p(t_info *info, va_list arg);

// NBR_SUMMARY
long long get_signed_argument(t_info* info, va_list arg);
char    *type_di(t_info *info, va_list arg);
//char    *type_o(t_info *info, va_list arg);
//char    *type_h(t_info *info, va_list arg);

#endif
