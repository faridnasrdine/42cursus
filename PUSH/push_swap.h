/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:26 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/21 17:49:18 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//---include---------------------------------------------
# include <limits.h>
# include <stdlib.h>
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
t_node			*ft_lstlast(t_node *lst);
t_node			*createt_node(int data);
int				list_size(t_node *head);

//--parsing-----------------------------------------------------
int				check_error(char **argv, int i, int j);
int				check_arranging(t_node *stack_a);
int				check_duplicate(t_node *stack_a);
int				check_args(char **av);
t_node			*check_nub_arg(int ac, char **av);
void			print_error(char **num, t_node **a, t_node **b);
void			ft_free(t_node **str);

//--sort--------------------------------------------------
void			radix_sort(t_node **stack_a, t_node **stack_b);
void			sort_three(t_node **head);
void			sort_lass_ten(t_node **stack_a, t_node **stack_b);
void			sort_stack(t_node **stack_a, t_node **stack_b);
int				find_biggest(t_node *head);
int				find_bits(int biggest_nbr);
void			set_index(t_node *head, int link_size);

// operatuions---------------------------------------------------------

void			ra(t_node **stack_a);
void			sa(t_node **stack_a);
void			rra(t_node **stack_a);
void			pa(t_node **stack_a, t_node **stack_b);
void			pb(t_node **stack_a, t_node **stack_b);

//--mimilibft---------------------------------------------------------
char			**ft_split(char const *s);
long int		ft_atoi(const char *nptr);
char			**free_split(char **split);

#endif