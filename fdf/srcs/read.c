/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:49:43 by dthan             #+#    #+#             */
/*   Updated: 2020/01/03 16:49:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int check_color(char **line)
{
    if (ft_strncmp(*line, "0x", 2) == 0 || ft_strncmp(*line, "0X", 2) == 0)
    {
        *line = *line + 2;
        if (*(*line + 6) != ' ')
            return (error_handle("Color is incorrect"));
        *line = *line + 7;
    }
    else
        return (error_handle("Invalid Hex sign"));
    return (EXIT_SUCCESS);
}

int check_line(char *line)
{
    char *valid_input = "-0123456789abcdefABCDEF, ";
    while (*line)
    {
        if (!(ft_strchr(valid_input, *line)))
            return (error_handle("Invalid Input"));
        if (*line == ',')
        {
            line++;
            if(check_color(&line))
                return (EXIT_FAILURE);
        }
        else
            line++;
    }
    return (EXIT_SUCCESS);
}

int get_line(int fd, t_list *lst)
{
    t_list *temp;
    int ret;
    char *line;

    while(ret = get_next_line(fd, &line))
    {
        if(!check_line(line))
            return (EXIT_FAILURE);
        temp = ft_lstnew(line, ft_strlen(line) + 1);
//        if (temp == NULL)
//            clean(temp);
        ft_lstadd(&lst, temp);
        ft_strdel(&line);
    }
    return (1);
}

/*
t_map *get_map(int width, int height)
{
    t_map *map;

    if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
        return (EXIT_FAILURE);
    map->x = width;
    map->y = height;
    return (map);
}

int ft_lstcount(t_line *lstline)
{
    int i;

    i = 0;
    while(lstline->content != NULL)
    {
        lstline = lstline->next;
        i++;
    }
    return (i);
}

int populate_map(t_map *map, t_line *lstline)
{

}
*/
int read_file(int fd, t_map *map)
{
    t_list *lst;

    get_line(fd, lst); //Getting the line list
    ft_putstr("OK");
    return (EXIT_SUCCESS);
//    map = get_map(ft_ctwords(lstline->content, ' '), ft_lstcount(lstline)); //getting the baisc info of the map, length, width
 //   close(fd);
 //   return (populate_map(map, lstline));
}