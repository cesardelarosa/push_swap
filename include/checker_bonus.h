/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:40:08 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/20 12:49:01 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

void		silent_swap(t_stacks *stacks, int type_move);
void		silent_rotate(t_stacks *stacks, int type_move);
void		silent_reverse_rotate(t_stacks *stacks, int type_move);
void		silent_push(t_stacks *stacks, int type_move);

t_stacks	*parser(int argc, char **argv);
int			check_order(t_list *a);

void		free_stacks(t_stacks *stacks);
void		ft_error(t_stacks *stacks, char **split);

#endif
