/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arranging.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:53:24 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:53:24 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int check_arranging(node *stack_a)
{
    int i;
    
    while(stack_a != NULL && stack_a->next != NULL)
    {   
        i = stack_a->data;
        stack_a = stack_a->next;
        if( i > stack_a->data)
            return (0);
    }
    return (1);
}