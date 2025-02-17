/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_arg_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:02 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/17 15:10:02 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_arg(char **av, t_node **stack_a)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		ft_add_back(stack_a, createt_node(ft_atoi(av[i])));
		i++;
	}
}

t_node	*check_nub_arg(int ac, char **av)
{
	t_node	*stack_a;
	int		i;
	t_node	*tmp;

	stack_a = NULL;
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (check_args(&av[i]))
			{
				tmp = check_cout(av[i]);
				while (tmp)
				{
					ft_add_back(&stack_a, createt_node(tmp->data));
					tmp = tmp->next;
				}
			}
			else
				print_error();
			i++;
		}
	}
	return (stack_a);
}
