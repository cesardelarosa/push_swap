/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:22:10 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/18 13:22:12 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "stacks.h"
# include "moves.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

t_stacks	*parser(int argc, char **argv);
void		free_stacks(t_stacks *stacks);
void		silent_swap(t_stacks *stacks, int type_move);
void		silent_rotate(t_stacks *stacks, int type_move);
void		silent_reverse_rotate(t_stacks *stacks, int type_move);
void		silent_push(t_stacks *stacks, int type_move);
int			check_order(t_list *a);
void		ft_error(void);

#endif
