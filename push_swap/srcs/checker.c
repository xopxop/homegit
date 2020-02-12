/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 04:07:46 by dthan             #+#    #+#             */
/*   Updated: 2020/02/12 04:07:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_args(char **args)
{
    while (args)
        while (*args)
            if (!ft_isdigit(**args))
                return (0);
    return (1);
}

int store_list(t_list *list, char **args)
{
    if (!check_args(args));
        return (0);
    while (args)
    {
        ft_lstnew(*args, sizeof(*args));
    }
}

int main(int ac, char **av)
{
    t_list list;

    if (ac < 2)
        ft_putendl_fd("Error", 2);
    else
    {
        if (!store_list(&list, av))
            ft_putendl_fd("Error", 2);
    }
    
}