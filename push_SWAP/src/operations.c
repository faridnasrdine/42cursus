/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:05 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:54:05 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ra(node **stack_a)
{
    node *temp;
    node *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = NULL;
    last = *stack_a;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
    write(1, "ra\n", 3);
}
void rb(node **stack_b)
{
    node *tmp;
    node *last;

    if(*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = NULL;
    last = *stack_b;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = tmp;
    write(1, "rb\n", 3);
}
void sa(node **stack_a)
{
    node *tmp;

    if(*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = (*stack_a)->next;
    (*stack_a)->next = tmp;
    write(1, "sa\n", 3);
}
void    sb(node **stack_b)
{
     node *tmp;

    if(*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = (*stack_b)->next;
    (*stack_b)->next = tmp;
    write(1, "sb\n", 3);
}

void    ss(node **stack_a, node **stack_b)
{
    node *tmp;

    if(!*stack_a || !*stack_b || !((*stack_a)->next) || !((*stack_b)->next))
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = (*stack_a)->next;
    (*stack_a)->next = tmp;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = (*stack_b)->next;
    (*stack_b)->next = tmp;
    write(1, "ss\n", 3);
}
