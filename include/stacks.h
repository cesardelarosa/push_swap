/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:56:21 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/13 13:38:50 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "libft.h"

typedef struct s_rotations
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		rr;
	int		rrr;
	int		n;
}			t_rotations;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		n;
	int		n_a;
	int		n_b;
}			t_stacks;

#endif
