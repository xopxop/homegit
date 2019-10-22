/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:32:53 by dthan             #+#    #+#             */
/*   Updated: 2019/10/21 16:59:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_H
# define LIBFT_H
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct	s_list 	*next;
}					t_list;

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
// Need to delete restrict
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);

// Home 21.10
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);

//strnstr
//strcmp
//strncmp

int	ft_atoi(const char *str);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isprint(int c);
int	ft_isascii(int c);

int	ft_toupper(int c);
int	ft_tolower(int c);

// Part II
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));



// ft_striteri
// ft_strmap
// ft_strmapi
// ft_strequ
// ft_strnequ
// ft_strub
// ft_strjoin
// ft_strtrim
// ft_strsplit
// ft_itoa
// ft_putchar
// ft_putstr
// ft_putendl
// ft_putnbr
// ft_putchar_fd
// ft_putstr_fd
// ft_putendl_fd
// ft_putnbr_fd

// BONUS PART
// ft_lstnew
// ft_lstdelone
// ft_lstdel
// ft_lstadd
// ft_lstiter
// ft_lstmap
//

#endif
