/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:53:53 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 10:43:27 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stacks.h"

void	ft_lstadd_back_psw(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst != NULL && new != NULL)
	{
		if (*lst != NULL)
		{
			last = ft_lstlast_psw(*lst);
			last->next = new;
			new->prev = last;
			new->next = *lst;
			(*lst)->prev = new;
		}
		else
		{
			*lst = new;
			new->next = new;
			new->prev = new;
		}
	}
}

t_stack	*ft_lstnew_psw(long content)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->num = content;
	result->next = result;
	result->prev = result;
	return (result);
}

t_stack	*ft_lstlast_psw(t_stack *lst)
{
	t_stack	*result;

	result = lst;
	if (result != NULL)
	{
		while (result->next != lst)
			result = result->next;
	}
	return (result);
}

// no sirve
void	ft_lstadd_front_psw(t_stack **lst, t_stack *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstclear_psw(t_stack **lst)
{
	t_stack	*current;
	t_stack	*head;
	t_stack	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	head = *lst;
	current = head->next;
	while (current != head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(head);
	*lst = NULL;
}

void	free_stacks(t_stacks *stacks)
{
	ft_lstclear_psw(stacks->stack[0]);
	ft_lstclear_psw(stacks->stack[1]);
	free(stacks->stack[0]);
	free(stacks->stack[1]);
	free(stacks);
}
