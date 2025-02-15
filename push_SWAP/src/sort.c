/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:07:46 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/15 17:54:49 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static node *max_node(node *stack)
{
    node *max_node;
    int max;

    if(!stack)
        return NULL;
    max_node = stack;
    max = stack->data;
    while(stack)
    {
        if(max < stack->data)
        {
            max = stack->data;
            max_node = stack;
        }
        stack =stack->next;
    }
    return (max_node);
    
}
void sort_three(node **stack_a)
{
    node *max;
    if(!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
        return;
    max = max_node(*stack_a);
    if((*stack_a) == max)
        ra(stack_a);
    if((*stack_a)->next == max)
        rra(stack_a);
    if((*stack_a)->data > (*stack_a)->next->data)
        sa(stack_a);
}

void sort_arg(node *stack_a, node *stack_b)
{
    int size;
    size = list_size(stack_a);
    if(size == 2 && check_arranging(stack_a) == 0)
        sa(&stack_a);
    if(size == 3 && check_arranging(stack_a) == 0)
        sort_three(&stack_a);
    if(size > 3 && check_arranging(stack_a) == 0)
        radix_sort(&stack_a, &stack_b);
}