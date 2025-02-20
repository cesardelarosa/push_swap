/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:50:57 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/20 12:50:58 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_order(t_list *a)
{
	t_list	*current;
	int		count;

	if (!a || !a->next)
		return (1);
	count = 0;
	current = a;
	while (current->next)
	{
		if (*(int *)(current->content) > *(int *)(current->next->content))
			count++;
		current = current->next;
	}
	if (*(int *)(current->content) > *(int *)(a->content))
		count++;
	return (count <= 1);
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	ft_lstclear(&stacks->a, free);
	ft_lstclear(&stacks->b, free);
	free(stacks);
}

void	ft_error(t_stacks *stacks, char **split)
{
	if (split != NULL)
		ft_free_split(split);
	if (stacks != NULL)
		free_stacks(stacks);
	write(2, "Error\n", 6);
	exit(1);
}
