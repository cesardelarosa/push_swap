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
#include <stdio.h>

void	printf_near(t_stack *stack, int bool)
{
	if(stack == NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	if(bool == 1)
		printf("\n beforeswap\n");
	else
		printf("\nafkterswap\n"); 
	printf("\nstack->num: %d\n", stack->num);
	printf("\nstack->next->num: %d\n", stack->next->num);
	printf("\nstack->prev->num: %d\n", stack->prev->num);
}
void print_stack(t_stack *lst)
{
	t_stack *current;

	if (!lst)
	{
		printf("Stack is empty\n");
		return;
	}

	current = lst;
	do
	{
		printf("Number: %d\n", current->num);
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
