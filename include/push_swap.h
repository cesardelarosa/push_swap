/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:22:29 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/18 13:22:33 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "stacks.h"

void		a_to_b(t_stacks *stacks);
void		b_to_a(t_stacks *stacks);
t_stacks	*parser(int argc, char **argv);
void		free_stacks(t_stacks *stacks);
void		align_a(t_stacks *stacks);

#endif
