/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:30:28 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/13 12:40:40 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

t_list	*ft_lstcpy(t_list *original)
{
	t_list	*copy;
	t_list	*node;
	int		*value_copy;

	copy = NULL;
	while (original)
	{
		value_copy = malloc(sizeof(int));
		if (!value_copy)
			ft_lstclear(&copy, free);
		*value_copy = *(int *)(original->content);
		node = ft_lstnew(value_copy);
		if (!node)
		{
			free(value_copy);
			ft_lstclear(&copy, free);
		}
		ft_lstadd_back(&copy, node);
		original = original->next;
	}
	return (copy);
}
