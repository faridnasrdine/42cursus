/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:23 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/16 17:42:00 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = check_nub_arg(ac, av);
	if (!stack_a)
		return (0);
	if (check_duplicate(stack_a))
	{
		set_index(stack_a, list_size(stack_a));
		sort_stack(&stack_a, &stack_b);
		ft_free(&stack_a);
		ft_free(&stack_b);
	}
	else
	{
		ft_free(&stack_a);
		print_error();
	}
	return (0);
}
