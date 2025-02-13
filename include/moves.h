/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:21:23 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 18:37:21 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "stacks.h"

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

void					swap(t_stacks *stacks, int type_move);
void					rotate(t_stacks *stacks, int type_move);
void					reverse_rotate(t_stacks *stacks, int type_move);
void					push(t_stacks *stacks, int type_move);

#endif
