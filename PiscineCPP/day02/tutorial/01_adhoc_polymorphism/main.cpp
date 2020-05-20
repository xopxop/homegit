/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:19:04 by dthan             #+#    #+#             */
/*   Updated: 2020/05/12 23:19:04 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"

int main(void) {
    Sample sample;
    float z = 3.14;

    sample.bar('a');
    sample.bar(42);
    sample.bar(z);
    sample.bar(sample);

    return 0;
}
