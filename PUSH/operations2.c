/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:35:03 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/18 17:04:25 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || (!(*stack)->next))
		return ;
	first = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	last = *stack;
	*stack = first;
	while (first)
	{
		if (first->next->next == NULL)
		{
			first->next = NULL;
			break ;
		}
		first = first->next;
	}
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **stack_a)
{
	rotate_reverse(&(*stack_a));
	write(1, "rra\n", 4);
}
