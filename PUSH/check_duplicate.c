/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:53:52 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/16 17:41:20 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_node *stack_a)
{
	t_node	*tmp;

	while (stack_a != NULL)
	{
		tmp = stack_a->next;
		while (tmp != NULL)
		{
			if (stack_a->data == tmp->data)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
