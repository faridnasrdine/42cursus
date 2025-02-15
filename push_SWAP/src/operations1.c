/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:09 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:54:09 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
void pa(node **stack_a, node **stack_b)
{
    if (*stack_b == NULL)
        return;

    node *tmp = *stack_b;
    *stack_b = (*stack_b)->next;  
    tmp->next = *stack_a;        
    *stack_a = tmp;             
    write(1, "pa\n", 3);
}


void pb(node **stack_a, node **stack_b)
{
    if (*stack_a == NULL) 
        return;

    node *tmp = *stack_a;
    *stack_a = (*stack_a)->next;  
    tmp->next = *stack_b;
    *stack_b = tmp;               
    write(1, "pb\n", 3);
}


void    rr(node **stack_a, node **stack_b)
{
    node *tmp;
    node *last;
    if(!*stack_a || !*stack_b || (!(*stack_a)->next) || (!(*stack_b)->next))
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = NULL;
    last = *stack_a;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = tmp;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = NULL;
    last = *stack_b;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = tmp;
    write(1, "rr\n", 3);
}
