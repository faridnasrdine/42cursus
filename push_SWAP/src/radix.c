/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:29 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:54:29 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_max_bit(node *stack)
{
    int max;
    int bit;

    bit = 0;
    max = stack->data;
    while(stack)
    {
        if(stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    while(max >> bit != 0)
        bit++;
    return bit;
}

void radix_sort(node **stack_a, node **stack_b)
{
    int bit;
    int i;
    int size;
    int j;

    bit = get_max_bit(*stack_a);
    i = 0;
    size = list_size(*stack_a);
    while(i < bit)
    {
        j = 0;
        while(j < size)
        {
            if((((*stack_a)->data >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while(list_size(*stack_b) > 0)
            pa(stack_a, stack_b);
        i++;
    }
}