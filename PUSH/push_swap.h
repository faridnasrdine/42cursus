/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:26 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/17 18:18:34 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//---include---------------------------------------------
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
//----struct--------------------------------------------
typedef struct node
{
	int			data;
	int			index;
	struct node	*next;
}				t_node;

//--creating----------------------------------------------------------
void			ft_add_back(t_node **stack, t_node *stack_new);
void			print_stack(t_node *stack);
t_node			*ft_lstlast(t_node *lst);
t_node			*createt_node(int data);
int				list_size(t_node *head);

//--parsing-----------------------------------------------------
int				check_error(char **argv, int i, int j);
int				check_arranging(t_node *stack_a);
int				check_duplicate(t_node *stack_a);
t_node			*check_cout(char *av);
int				check_args(char **av);
t_node			*check_nub_arg(int ac, char **av);
void			print_error(t_node **a, t_node **b);
void			ft_free(t_node **str);
void			list_arg(char **av, t_node **stack_a);

//--sort--------------------------------------------------
void			radix_sort(t_node **stack_a, t_node **stack_b);
void			sort_three(t_node **head);
void			sort_five(t_node **stack_a, t_node **stack_b);
void			sort_stack(t_node **stack_a, t_node **stack_b);
int				find_biggest(t_node *head);
int				find_bits(int biggest_nbr);
void			set_index(t_node *head, int link_size);
// operatuions---------------------------------------------------------

void			ra(t_node **stack_a);
void			rb(t_node **stack_b);
void			sa(t_node **stack_a);
void			sb(t_node **stack_b);
void			rra(t_node **stack_a);
void			rrb(t_node **stack_b);
void			ss(t_node **stack_a, t_node **stack_b);
void			pa(t_node **stack_a, t_node **stack_b);
void			pb(t_node **stack_a, t_node **stack_b);
void			rr(t_node **stack_a, t_node **stack_b);
void			rrr(t_node **stack_a, t_node **stack_b);
//--mimilibft---------------------------------------------------------
char			**ft_split(char const *s);
int				ft_atoi(const char *nptr);
char			**free_split(char **split);

#endif