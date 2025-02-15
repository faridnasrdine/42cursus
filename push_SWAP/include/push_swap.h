/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:26 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/13 16:54:26 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

//---include---------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//----struct--------------------------------------------
typedef struct node
{
	int data;
	struct node *next;
} node;

//--creating----------------------------------------------------------
void	ft_add_back(node **stack, node *stack_new);
void	print_stack(node *stack);
node	*ft_lstlast(node *lst);
node	*createnode(int data);
int		list_size(node *head);

//--parsing-----------------------------------------------------
int		check_error(char **argv, int i, int j);
int		check_arranging(node *stack_a);
int		check_duplicate(node *stack_a);
node	*check_cout(char *av);
int		check_args(char **av);
node	*check_nub_arg(int ac, char **av);
void	print_error(void);
void	ft_free(node **str);
void	list_arg(char **av, node **stack_a);

//--sort--------------------------------------------------
void	radix_sort(node **stack_a, node **stack_b);
void	sort_arg(node *stack_a, node *stack_b);
void	sort_three(node **stack_a);
int		get_max_bit(node *stack);

// operatuions---------------------------------------------------------

void	ra(node **stack_a);
void	rb(node **stack_b);
void	sa(node **stack_a);
void	sb(node **stack_b);
void	rra(node **stack_a);
void	rrb(node **stack_b);
void	ss(node **stack_a, node **stack_b);
void	pa(node **stack_a, node **stack_b);
void	pb(node **stack_a, node **stack_b);
void	rr(node **stack_a, node **stack_b);
void	rrr(node **stack_a, node **stack_b);
//--mimilibft---------------------------------------------------------
char	**ft_split(char const *s);
int		ft_atoi(const char *nptr);
char	**free_split(char **split);


#endif