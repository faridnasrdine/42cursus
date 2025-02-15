/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_arg_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:02 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:54:02 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void list_arg(char **av, node **stack_a)
{
    int i = 0;
    while (av[i] != NULL)
    {
        ft_add_back(stack_a, createnode(ft_atoi(av[i])));
        i++;
    }
}

node *check_nub_arg(int ac, char **av)
{
    node *stack_a = NULL;
    int i = 1;

    if (ac > 1)
    {
        while (i < ac)
        {
            if (check_args(&av[i]))
            {
                node *tmp = check_cout(av[i]);
                while (tmp)
                {
                    ft_add_back(&stack_a, createnode(tmp->data));
                    tmp = tmp->next;
                }
            }
            else
                print_error();

            i++;
        }
    }
    return stack_a;
}
// node *check_nub_arg(int ac, char **av)
// {
//     node *stack_a;

//     if(ac > 1)
//     {
//         stack_a = NULL;
//         if(ac == 2)
//         {
//             if(check_args(av))
//                 stack_a = check_cout(av);
//             else
//                 print_error();
//         }
//         else
//         {
//             if(check_args(av))
//                 list_arg(av, &stack_a);
//             else
//                 print_error();
//         }
//         return stack_a;
//     }
//     return 0
// }
