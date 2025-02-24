/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:07:46 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/18 17:11:30 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **head)
{
	int	biggest;

	biggest = find_biggest(*head);
	if ((*head)->index == biggest)
		ra(head);
	else if ((*head)->next->index == biggest)
		rra(head);
	if ((*head)->index > (*head)->next->index)
		sa(head);
}

static int	min_nuber(t_node *stack)
{
	int	i;
	int	min;
	int	min_index;

	min_index = stack->index;
	i = 0;
	min = 0;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min = i;
		}
		i++;
		stack = stack->next;
	}
	return (min);
}

static void	min_in_top(t_node **stack)
{
	int	i;
	int	size;

	i = min_nuber(*stack);
	size = list_size(*stack);
	if (i <= size / 2)
	{
		while (i-- > 0)
			ra(stack);
	}
	else
	{
		i = size - i;
		while (i-- > 0)
			rra(stack);
	}
}

void	sort_lass_ten(t_node **stack_a, t_node **stack_b)
{
	while (list_size(*stack_a) > 3)
	{
		min_in_top(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (list_size(*stack_b) > 0)
	{
		pa(stack_a, stack_b);
	}
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	if (!check_arranging(*stack_a) && size <= 3)
		sort_three(stack_a);
	else if (!check_arranging(*stack_a) && size <= 10)
		sort_lass_ten(stack_a, stack_b);
	else if (!check_arranging(*stack_a))
		radix_sort(stack_a, stack_b);
}
