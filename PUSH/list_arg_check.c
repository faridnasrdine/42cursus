/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_arg_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:02 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/22 10:05:57 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_argument(const char *arg, t_node **stack)
{
	char	**tokens;
	t_node	*new_node;

	long (j), nb;
	tokens = ft_split(arg);
	if (!tokens || !*tokens)
		return (free(tokens), print_error(NULL, stack, NULL));
	j = 0;
	while (tokens[j])
	{
		nb = ft_atoi(tokens[j]);
		if (nb > INT_MAX || nb < INT_MIN)
			print_error(tokens, stack, NULL);
		new_node = createt_node(nb);
		if (!new_node)
		{
			free_split(tokens);
			ft_free(stack);
		}
		ft_add_back(stack, new_node);
		j++;
	}
	free_split(tokens);
}

t_node	*check_nub_arg(int ac, char **av)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		if (check_args(&av[i]))
		{
			process_argument(av[i], &stack);
		}
		else
			print_error(NULL, &stack, NULL);
		i++;
	}
	return (stack);
}
