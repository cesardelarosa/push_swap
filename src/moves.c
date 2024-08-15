/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpedrer <adpedrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:48:44 by adpedrer          #+#    #+#             */
/*   Updated: 2024/08/15 00:51:01 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **a, t_stack **b, int type_move)
{
	if( MOVE_PA == type_move)
	{
		push_node(b, a, NULL);
		ft_putstr(PA);
	}
	else if( MOVE_PB == type_move)
	{
		push_node(a, b, NULL);
		ft_putstr(PB);
	}
}

void	push_node(t_stack **src, t_stack **dest, t_stack *tmp)
{
	if (src && *src)
	{
		tmp = *src;
		if (tmp->next == tmp) 
			*src = NULL;
		else
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			*src = tmp->next;
		}
		if (*dest == NULL)
		{
			tmp->next = tmp;
			tmp->prev = tmp;
		}
		else
		{
			tmp->next = *dest;
			tmp->prev = (*dest)->prev;
			(*dest)->prev->next = tmp;
			(*dest)->prev = tmp;
		}
		*dest = tmp;
	}
}
void	reverse_rotate(t_stack **a, t_stack **b, int type_move)
{
	if( MOVE_RRA == type_move)
	{
		reverse_rotate_node(a);
		ft_putstr(RRA);
	}
	else if( MOVE_RRB == type_move)
	{
		reverse_rotate_node(b);
		ft_putstr(RRB);
	}
	else if( MOVE_RRR == type_move)
	{
		reverse_rotate_node(a);
		reverse_rotate_node(b);
		ft_putstr(RRR);
	}
}

void	reverse_rotate_node(t_stack **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->prev;
	}
}

void	rotate(t_stack **a, t_stack **b, int type_move)
{
	if( MOVE_RA == type_move)
	{
		rotate_node(a);
		ft_putstr(RA);
	}
	else if( MOVE_RB == type_move)
	{
		rotate_node(b);
		ft_putstr(RB);
	}
	else if( MOVE_RR == type_move)
	{
		rotate_node(a);
		rotate_node(b);
		ft_putstr(RR);
	}
}

void	rotate_node(t_stack **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->next;
	}
}

void swap(t_stack **a, t_stack **b, int type_move)
{
	if( MOVE_SA == type_move)
	{
		swap_node(a);
		ft_putstr(SA);
	}
	else if( MOVE_SB == type_move)
	{
		swap_node(b);
		ft_putstr(SB);
	}
	else if( MOVE_SS == type_move)
	{
		swap_node(a);
		swap_node(b);
		ft_putstr(SS);
	}
}

void swap_node(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	// Verifica que el stack y los dos primeros nodos existen y que el segundo nodo no es el mismo que el primero.
	if (stack && *stack && (*stack)->next && (*stack)->next != *stack)
	{
		//printf_near(*stack, 0);
		first = *stack;
		second = first->next;

		// Actualiza los punteros del primer nodo.
		first->next = second->next;
		if (second->next)
			second->next->prev = first;

		// Actualiza los punteros del segundo nodo.
		second->next = first;
		second->prev = first->prev;
		if (first->prev)
			first->prev->next = second;

		// Actualiza el puntero al nodo anterior del primer nodo.
		first->prev = second;

		// Actualiza el puntero de la pila para que apunte al segundo nodo.
		*stack = second;
		//printf_near(*stack, 1);
	}
}
