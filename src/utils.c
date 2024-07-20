/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:39:07 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/07/13 12:23:33 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *lst)
{
	int	min;

	min = *(int *)(lst->content);
	while (lst)
	{
		if (*(int *)(lst->content) < min)
			min = *(int *)(lst->content);
		lst = lst->next;
	}
	return (min);
}

int	find_max(t_list *lst)
{
	int	max;

	max = *(int *)(lst->content);
	while (lst)
	{
		if (*(int *)(lst->content) > max)
			max = *(int *)(lst->content);
		lst = lst->next;
	}
	return (max);
}
