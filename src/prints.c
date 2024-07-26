/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpedrer <adpedrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:49:21 by adpedrer          #+#    #+#             */
/*   Updated: 2024/07/25 22:57:03 by adpedrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	printf_near(t_stack *stack, int bool)
{
	if(stack == NULL)
	{
		ft_printf("Stack is empty\n");
		return;
	}
	if(bool == 1)
		ft_printf("\n beforeswap\n");
	else
		ft_printf("\nafkterswap\n"); 
	ft_printf("\nstack->num: %d\n", stack->num);
	ft_printf("\nstack->next->num: %d\n", stack->next->num);
	ft_printf("\nstack->prev->num: %d\n", stack->prev->num);
}
void print_stack(t_stack *lst)
{
	t_stack *current;

	if (!lst)
	{
		ft_printf("Stack is empty\n");
		return;
	}

	current = lst;
	do
	{
		ft_printf("Number: %d\n", current->num);
		current = current->next;
	} while (current != lst);
}

void print_result(char **result)
{
	int i = 0;

	while (result[i])
	{
		printf("result[%d]: %s\n", i, result[i]);
		i++;
	}
}

