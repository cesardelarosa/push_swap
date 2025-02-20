/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:22:29 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/20 12:47:11 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define MOVE_SA 2
# define MOVE_SB 3
# define MOVE_SS 6

# define MOVE_RA 5
# define MOVE_RB 7
# define MOVE_RR 35

# define MOVE_RRA 11
# define MOVE_RRB 13
# define MOVE_RRR 143

# define MOVE_PA 17
# define MOVE_PB 19

# define PA "pa\n"
# define PB "pb\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		n;
	int		n_a;
	int		n_b;
}			t_stacks;

void		push_node(t_list **src, t_list **dest);
void		reverse_rotate_node(t_list **stack);
void		rotate_node(t_list **stack);
void		swap_node(t_list **stack);

void		swap(t_stacks *stacks, int type_move);
void		rotate(t_stacks *stacks, int type_move);
void		reverse_rotate(t_stacks *stacks, int type_move);
void		push(t_stacks *stacks, int type_move);

t_stacks	*parser(int argc, char **argv);
void		a_to_b(t_stacks *stacks);
void		b_to_a(t_stacks *stacks);
void		align_a(t_stacks *stacks);

void		free_stacks(t_stacks *stacks);
void		ft_error(t_stacks *stacks, char **split);

#endif
