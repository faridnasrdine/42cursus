/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:23 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:54:23 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int ac, char **av)
{
    node *stack_a = NULL;
    node *stack_b = NULL;

    stack_a = check_nub_arg(ac, av);
    if (!stack_a)
        return 0;
    if (check_duplicate(stack_a))
    {
        if (list_size(stack_a) == 1)
        {
            ft_free(&stack_a);
            return 0;
        }
        else 
            sort_arg(stack_a, stack_b);
        ft_free(&stack_a);
        ft_free(&stack_b);
    }
    else
    {
        ft_free(&stack_a);
        print_error();
    }
    return 0;
}
