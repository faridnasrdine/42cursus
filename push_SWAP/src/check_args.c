/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:53:19 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:53:19 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_alpha(char c)
{
    if((c >= 58 && c <= 126) || (c  >= 33 && c <= 42)
        || (c == 44) || (c == 46) || (c == 47))
        return (1);
    return (0);
}

void check_alpha(char **av)
{
    int i;
    int j;

    i = 0;
    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if(is_alpha(av[i][j]) == 1)
            {
                print_error();
            }
            j++;
        }
        i++;
    }
}
int check_args(char **av)
{
    check_alpha(av);
    if(check_error(av, 0, 0) == 0)
        return 0;
    return 1;
}