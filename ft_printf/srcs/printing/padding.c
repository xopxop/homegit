/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:13:49 by dthan             #+#    #+#             */
/*   Updated: 2019/12/28 14:13:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void ft_right_just(t_info *info, char **str, char *new)
{
    char extra;

    extra = 0;
    if (info->flags & ZERO)
    {
        extra = (!ft_isdigit((*str)[0]) && info->specifier == spec_int) ? (*str)[0] : 0;
        ft_memset(new, '0', info->field_width - ft_strlen(*str) + !!extra);
        if (extra)
        {
            new[0] = extra;
            (*str)[0] = '0';
        }
    }
    else
    {
        ft_memset(new, ' ', info->field_width - ft_strlen(*str));
        if ((info->flags & PLUS_SIGN) && **str != '-')
            new[info->field_width -ft_strlen(*str)] = ((*str)[0] == '-') ? '-' : '+';
    }
    ft_strcpy(new + info->field_width - ft_strlen(*str) + !!extra, *str + !!extra);
}

/*
** This function pad_handle will be used for padding, type d,i,u
** 
*/

void ft_pad_handle(t_info *info, char **str)
{
    char *new;

    if (info->field_width == 0 || ft_strlen(*str) >= (size_t)info->field_width)
        return ;
    new = ft_strnew(info->field_width);
    if (info->flags & MINUS_SIGN)
    {
        ft_strcpy(new, *str);
        ft_memset(new + ft_strlen(*str), ' ', info->field_width - ft_strlen(*str));
    }
    else
        ft_right_just(info, str, new);
    free(*str);
    *str = new;
    return ;
}

/*
** This ft_prec_nums is using for type_di and type_u
** This ft will create a string and return it back
** Note:if the percision == 0 and the number is 0 -> nothing to be printed
**      if percision < strlen ->no percision (if no percision -> automaticly
**                                              make percision == 1)
** For normal number: first check the sign of the string to check if the new
** string need one more space or not, if there is sign then the first position
** at the new string will be reserve for the sign ('-' || '+' || ' ', remember
** if there are plus and space flags then plus will be always be printed not
** space), move the the next position of the string
** Secondly, filling the '0' with n time
** Thirdly, filling the digit from the string to new string
*/

void    ft_prec_nums(t_info *info, char **str)
{
    char *new;
    char extra;
    char *orig;

    orig = *str;
    if (info->percision == 0 && !ft_strcmp("0", *str))
    {
        **str = '\0';
        return ;
    }
    if (info->percision == -1)
        info->percision = 1;
    if (info->percision < (int) ft_strlen(*str))
        return ;
    extra = (!ft_isdigit((*str)[0])) ? (*str)[0] : 0;
    if (extra)
        (*str)++;
    new = ft_strnew(info->percision + !!extra);
    ft_memset(new + !!extra, '0', info->percision - ft_strlen(*str));
    ft_strcpy(new + info->percision - ft_strlen(*str) + !! extra, *str);
    if (extra)
        new[0] = extra;
    free(orig);
    *str = new;
}

/*
** This function ft_prec_handle is using for type s only
** when there is no precision, printing normal string
** if there is precision, then the string will be null-terminated at
** the precision number (only string's length is smaller than the percision)
*/

void ft_prec_handle(t_info *info, char **str)
{
    if (info->percision == -1)
        return ;
    if (ft_strlen(*str) <= (size_t)info->percision)
        return ;
    (*str)[info->percision] = '\0';
}

void ft_percisionSmallerThanSTRLEN(t_info *info, char **str)
{
    char *origin;
    char *new;
    char extra;

    origin = *str;
    extra = ((info->flags & PLUS_SIGN) || (info->flags & SPACE)) ? \
            ((info->flags & PLUS_SIGN) ? '+' : ' ') : 0;
    new = ft_strnew(ft_strlen(*str) + !!extra + 2);
    if (extra)
        new[0] = extra;
    ft_strncpy(new + !!extra, "0x", 2);
    ft_strcpy(new + !!extra + 2, *str);
    free(origin);
    *str = new;
}

void ft_percision_hex(t_info *info, char **str)
{
    char *origin;
    char *new;
    char extra;

    origin = *str;
    if (info->percision <= (int)ft_strlen(origin))
    {
        ft_percisionSmallerThanSTRLEN(info, str);
        return ;
    }
    extra = ((info->flags & PLUS_SIGN) || (info->flags & SPACE)) ? \
            ((info->flags & PLUS_SIGN) ? '+' : ' ') : 0;
    new = ft_strnew(info->percision + 2 + !!extra);
    ft_memset(new + !!extra + 2, '0', info->percision - ft_strlen(*str));
    ft_strcpy(new + !!extra + 2 + info->percision - ft_strlen(*str), *str);
    if (extra)
        new[0] = extra;
    ft_strncpy(new + !!extra, "0x", 2);
    free(origin);
    *str = new;
}
