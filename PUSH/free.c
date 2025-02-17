/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:53:59 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/17 17:31:06 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_node **str)
{
	t_node	*tmp;

	if (!str || !*str)
		return ;
	while (*str)
	{
		tmp = *str;
		*str = (*str)->next;
		free(tmp);
	}
	*str = NULL;
}
