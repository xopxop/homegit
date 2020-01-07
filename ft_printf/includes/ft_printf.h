/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:45:44 by dthan             #+#    #+#             */
/*   Updated: 2019/12/31 15:49:58 by dthan            ###   ########.fr       */
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
# define STDOUT 1
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

typedef struct		s_info
{
	int		flags;
	int		field_width;
	int		percision;
	t_length		length;
	t_specifier	specifier;
}			t_info;


/*
** Core file
*/

int	ft_printf(char const *format, ...);
int	full_str_printing(const char *format, va_list args, t_info *info);
int	parse_and_print(const char *format, va_list args, size_t *pos, t_info *info);

/*
** -------------------------Parsing part file---------------------------------
*/
void	parsing(const char *format, va_list args, size_t *pos, t_info *info);
void	struct_init(t_info *info);

/*
** Parsing helper file
*/

int	ft_skip_atoi(const char *format, size_t *pos);

/*
** Filling struct file
*/

void			get_flags(const char *format, size_t *pos, t_info *info);
void			get_field_width(const char *format, size_t *pos, va_list arg, t_info *info);
void			get_precision(const char *format, size_t *pos, va_list arg, t_info *info);
void			get_length(const char *format, size_t *pos, t_info *info);
void			get_specifier(const char *format, size_t *pos, t_info *info);

/*
** -------------------------Printing files------------------------------------
*/

int			printing(t_info *info, va_list arg);

/*
** Get number to string file
*/

char			*ft_number_conversion(unsigned long long num, int mask, int shiff_nbr, int strlen, char *s);
void			put_floating_point_to_string(long double num, t_info *info, char **str);


long long		get_signed_argument(t_info* info, va_list arg);
unsigned long long	get_unsigned_argument(t_info* info, va_list arg);

/*
** Padding file
*/

void			ft_pad_handle(t_info *info, char **str);
void			ft_right_just(t_info *info, char **str, char *new);
void			ft_right_just_special_case(t_info *info, char **str, char *new);
void			ft_special_case(t_info *info, char **str);

/*
** Percision file
*/

void			ft_prec_handle(t_info *info, char **str);
void			ft_prec_nums(t_info *info, char **str);
void			ft_percision_hex(t_info *info, char **str);
void			ft_percisionSmallerThanSTRLEN(t_info *info, char **str);

/*
** Type_C
*/

void			type_c(t_info *info, va_list arg, size_t *ct);

/*
** Type_S
*/

void			type_s(t_info *info, va_list arg, size_t *ct);

/*
** TYPE_P
*/

void			type_p(t_info *info, va_list arg, size_t *ct);

/*
** TYPE SIGNED INTEGER
*/

void			type_di(t_info *info, va_list arg, size_t *ct);

/*
** Type unsigned integer
*/

void			type_u(t_info *info, va_list arg, size_t *ct);

/*
** Type Octal number
*/

void			ft_handle_alt(t_info *info, char **str);
void			type_o(t_info *info, va_list arg, size_t *ct);

/*
** Type Hexadecimal number
*/

void			ft_percisionSmallerForxX(t_info *info, char **str);
void			ft_prec_hex(t_info *info, char **str);
void			type_x(t_info *info, va_list arg, size_t *ct);
void			small_x(t_info *info, va_list arg, char **output);
void			big_x(char **output);

/*
** Type floating point
*/

int			ft_isnan(double num);
int			ft_isinf(double num);
int			special_case(char **s, double num);
long double		ft_calc_modulo(double num, int *str_size);
void			ft_handle_decimal(long double *nb, char **str, int *i, long double modulo);
void			ft_handle_fractional(char **str, int *i, long double nb, t_info *info);
void			type_f(t_info *info, va_list arg, size_t *ct);

/*
**
*/

void	type_percent(t_info *info, __attribute__((unused)) va_list arg, size_t *ct);

/*
** Printing helper
*/

char	*ft_strjoin_and_free_string1(char *string1, char *string2);
char	*ft_strjoin_and_free_string2(char *string1, char *string2);

#endif
