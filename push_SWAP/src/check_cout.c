/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:53:48 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:53:48 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

node *check_cout(char *av)
{
    char **tmp;
    node *stack_a = NULL;

    tmp = ft_split(av);
    if (!tmp)
        return NULL;
    list_arg(tmp, &stack_a);
    free_split(tmp);
    return stack_a;
}
 