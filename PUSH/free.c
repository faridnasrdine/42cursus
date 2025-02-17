/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:53:59 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/17 15:05:15 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_node **str)
{
	t_node	*tmp;
	if (!str || !*str)  // Check if the list or pointer is NULL
		return;
	while (*str)
	{
		tmp = *str;
		*str = (*str)->next;
		free(tmp);
	}
}
