/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pare_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:15:23 by dthan             #+#    #+#             */
/*   Updated: 2020/02/21 18:15:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int parse_input(char **input)
{
    int options;
    char **ptr;

    ptr = input;
    options = 0;
    ptr++;
    while (ptr)
    {
        while(*ptr)
        {
            if (**ptr == 'l')
                options |= L_OPTION;
            else if (**ptr == 'R')
                options |= CAP_R_OPTION;
            else if (**ptr == 'a')
                options |= A_OPTION;
            else if (**ptr == 'r')
                options |= R_OPTION;
            else if (**ptr == 't')
                options |= T_OPTION;
            *ptr++;
        }
        ptr++;
    }
    return (options);
}