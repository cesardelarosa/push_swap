/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:54:43 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/13 20:01:38 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_order(t_list *a)
{
	t_list	*tmp;

	if (!a || !(a->next))
		return (1);
	tmp = a;
	while (tmp && tmp->next)
	{
		if (*(int *)(tmp->content) > *(int *)(tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	ft_lstclear(&stacks->a, free);
	ft_lstclear(&stacks->b, free);
	free(stacks);
}
