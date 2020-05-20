/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:18:50 by dthan             #+#    #+#             */
/*   Updated: 2020/05/01 00:18:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void    byPtr(std::string* str)
{
    *str += " and ponies";
}

void    byConstPtr(std::string const * str)
{
    std::cout << *str << std::endl;
}

void    byRef(std::string& str)
{
    str += " and ponies";
}

void    byConstRef(std::string const & str)
{
    std::cout << str << std::endl;
}

int     main()
{
    std::string str = "i like butterflies";

    std::cout << str << std::endl;
    byPtr(&str);
    byConstPtr(&str);

    str = "i like otters";

    std::cout << str << std::endl;
    byRef(str);
    byConstRef(str);

    return (0);
}
