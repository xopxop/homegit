/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:15:40 by dthan             #+#    #+#             */
/*   Updated: 2020/02/28 14:15:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void print_long_list(t_info *file)
{
    //... + (owner + group + other +) extended atratribute +
    // owner name + group name + filezie + month + date + 
    // hour:second + filename
    ft_printf("%s %s %s %d %s....")
}

void print_output(t_finfo *file, int options)
{
    if (options & LONG_LIST_FORMAT)
        print_long_list(file);
    ft_printf("%s\n", file->name);
}

void display(t_file *file)
