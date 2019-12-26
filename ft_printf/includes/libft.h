/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:32:15 by dthan             #+#    #+#             */
/*   Updated: 2019/12/06 17:33:22 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdint.h>

int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s, size_t count);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
char		*ft_itoa_signed_longlong(long long n);
char		*ft_itoa_unsigned_longlong(unsigned long long nbr);
char	*ft_strjoin(char const *string1, char const *string2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *dest, const char *src);

#endif
