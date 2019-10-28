/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:28:34 by dthan             #+#    #+#             */
/*   Updated: 2019/10/28 15:17:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstdelone
 * void	ft_lstelone(t_list **alst, void (*del)(void *, size_t));
 * DESCRIPTION: Takes as a parameter a link's pointer address and frees the
 * memory of the link's content using the function del given as a parameter,
 * the frees the link's memory using free(3). The memory of next must not be
 * freed under any circumstance. Finally, the pointer to the link tha was just
 * freed must be set to NULL (quite similar to the function fT-memdel in the
 * mandatory part)
 * PARAM.#1: The adress of a pointer to a link that needs to be freed.
 * RETURN VALUE: None
 * Libc funtcions: free(3)
 */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
