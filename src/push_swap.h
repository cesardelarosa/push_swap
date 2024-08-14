/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpedrer <adpedrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:44:47 by adpedrer          #+#    #+#             */
/*   Updated: 2024/07/26 01:52:19 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"


typedef struct	s_operations
{
	int	ra;
	int	rb;
	int	n;
}	t_operations;

typedef struct s_stack t_stack;

struct       s_stack
{ 
    t_stack *prev;
    t_stack *next;
    int     num;
};

typedef struct	s_stacks
{
	t_stack	**stack[2];
	int	n[2];
}	t_stacks;

int	abs(int n);
int	max(int a, int b);
int	elements(t_stack **a);
void stacks_initiator(t_stack ***a, t_stack ***b);
void	order(t_stacks *stacks);
void	ft_lstadd_back_psw(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_psw(t_stack *lst);
void	ft_lstadd_front_psw(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew_psw(long content);
void	ft_lstclear_psw(t_stack **lst);
void	error(int i);
long	atoi_psw(char *str);
void	check_duplicates(char **nums);
void	print_stack(t_stack *head);
int count_tokens(int argc, char **argv);
void	stack_creator(t_stack **a, int argc, char **argv);
void	stack_creator_add(t_stack **a, char **nums);
void	free_split(char **split);
int	check_order(t_stack **a);
void	swap(t_stack **a, t_stack **b, int type_move);
void	swap_node(t_stack **stack);
void	printf_near(t_stack *stack, int bool);
void    print_result(char **result);
///////moves////////
void	rotate(t_stack **a, t_stack **b, int type_move);
void	rotate_node(t_stack **stack);
void	reverse_rotate(t_stack **a, t_stack **b, int type_move);
void	reverse_rotate_node(t_stack **stack);
void	push(t_stack **a, t_stack **b, int type_move);
void	push_node(t_stack **src, t_stack **dest, t_stack *tmp);
/////////moves////////

void	swap(t_stack **a, t_stack **b, int type_move);
void	swap_node(t_stack **stack);
void	rotate(t_stack **a, t_stack **b, int type_move);
void	rotate_node(t_stack **stack);


///////DEFINES///////////

/* ================= MOVEMENTS =================== */

#define MOVE_SA 1
#define MOVE_SB 2
#define MOVE_SS 12//
#define MOVE_RA 3
#define MOVE_RB 4
#define MOVE_RR 34
#define MOVE_RRA 5
#define MOVE_RRB 6
#define MOVE_RRR 56
#define MOVE_PA 8
#define MOVE_PB 9
/* ================= MESSAGES ==================== */
#define PA "pa\n"
#define PB "pb\n"
#define SA "sa\n"
#define SB "sb\n"
#define SS "ss\n"
#define RA "ra\n"
#define RB "rb\n"
#define RR "rr\n"
#define RRA "rra\n"
#define RRB "rrb\n"
#define RRR "rrr\n"


#endif
