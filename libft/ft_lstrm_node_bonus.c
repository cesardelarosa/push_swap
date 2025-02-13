/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm_node_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:31:40 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/13 12:31:42 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrm_node(t_list **list, t_list *target)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *list;
	while (current)
	{
		if (current == target)
		{
			if (prev)
				prev->next = current->next;
			else
				*list = current->next;
			ft_lstdelone(current, free);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
