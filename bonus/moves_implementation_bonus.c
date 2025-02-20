/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_implementation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:13:33 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/20 12:15:11 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push_node(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (src && *src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	reverse_rotate_node(t_list **stack)
{
	t_list	*prev;
	t_list	*curr;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	prev = NULL;
	curr = *stack;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev)
		prev->next = NULL;
	curr->next = *stack;
	*stack = curr;
}

void	rotate_node(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	head = *stack;
	*stack = head->next;
	head->next = NULL;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
}

void	swap_node(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}
