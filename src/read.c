/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 04:50:59 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/15 15:27:37 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "libft.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	read_args(t_list **a, char **numbers)
{
	int	*content;

	while (*numbers)
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			ft_error();
		*content = ft_atoi(*numbers);
		ft_lstadd_back(a, ft_lstnew(content));
		numbers++;
	}
}

void	check(t_list *current)
{
	t_list	*compare;

	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (*(int *)current->content == *(int *)compare->content)
				ft_error();
			compare = compare->next;
		}
		current = current->next;
	}
}

