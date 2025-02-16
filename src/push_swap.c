/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:54:43 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/16 18:58:37 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = parser(argc, argv);
	a_to_b(stacks);
	b_to_a(stacks);
	align_a(stacks);
	free_stacks(stacks);
	return (0);
}
