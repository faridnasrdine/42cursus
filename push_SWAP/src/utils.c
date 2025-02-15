/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:38 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:54:38 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

node *createnode(int data)
{
	node	*new;

	new = malloc(sizeof (node));
	if (!new)
		return NULL;
	new->data = data;
	new->next = NULL;
	return (new);
}

node	*ft_lstlast(node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void	ft_add_back(node **stack, node *stack_new)
{
    node *tmp;

	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
    {
		tmp = ft_lstlast(*stack);
        tmp->next = stack_new;
    }
}

int list_size(node *head)
{
    int size;
    size = 0;
    while(head)
    {
        size++;
        head = head->next;
    }
    return size;
}
// void print_stack(node *stack)
// {
//     while(stack)
//     {
//         ft_putnbr_fd(stack->data, 1);
//         ft_putchar_fd(' ', 1);
//         stack = stack->next;
//     }
//     ft_putchar_fd('\n', 1);
// }
