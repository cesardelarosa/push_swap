/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:00:00 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/13 09:29:40 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "moves.h"
#include "stacks.h"
#include <limits.h>

/*
** get_target_index:
** Calcula el índice en la pila A en el que debe insertarse el número 'n'.
** Se recorre A “como si fuera circular”: se obtiene el último nodo y se
** compara el valor actual con el anterior. Si 'n' encaja entre ambos se
** devuelve ese índice; si no, se devuelve el índice donde se encuentra el
** valor mínimo.
*/
static int	get_target_index(int n, t_list *a)
{
	int		len;
	int		i;
	int		ext;
	int		ext_idx;
	t_list	*last;
	t_list	*prev;
	t_list	*curr;
	int		curr_val;
	int		prev_val;

	len = ft_lstsize(a);
	last = ft_lstlast(a);
	ext = *(int *)(a->content);
	ext_idx = 0;
	i = 0;
	prev = last;
	curr = a;
	while (i < len)
	{
		curr_val = *(int *)(curr->content);
		prev_val = *(int *)(prev->content);
		if (n <= curr_val && n >= prev_val)
			return (i);
		if (curr_val < ext)
		{
			ext = curr_val;
			ext_idx = i;
		}
		prev = curr;
		curr = curr->next;
		i++;
	}
	return (ext_idx);
}

/*
** get_rotation:
** Dado un índice 'pos' y el tamaño de la pila 'size', determina el número
** mínimo de movimientos (positivo para rotate, negativo para reverse_rotate)
** para llevar el elemento de la posición 'pos' a la cima.
*/
static int	get_rotation(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

/*
** combined_cost:
** Calcula el costo total de dos rotaciones (ra y rb) aprovechando que si ambas
** rotaciones van en la misma dirección se pueden hacer simultáneas (usando rr o rrr)
** y el costo es el máximo; si van en direcciones contrarias se suman.
*/
static int	combined_cost(int ra, int rb)
{
	if ((ra >= 0 && rb >= 0) || (ra < 0 && rb < 0))
		return (ft_max(ft_abs(ra), ft_abs(rb)));
	return (ft_abs(ra) + ft_abs(rb));
}

/*
** run_best_rotation_sequence:
** Recorre la pila B y, para cada elemento, calcula:
**   - ra: rotaciones en A para insertar el número (usando get_target_index y get_rotation)
**   - rb: rotaciones en B para llevar el elemento a la cima
**   - n : costo total de ese movimiento
** Se elige el movimiento de menor costo y se ejecuta la secuencia de rotaciones
** aprovechando movimientos conjuntos (rr/rrr).
*/
static void	run_best_rotation_sequence(t_stacks *stacks)
{
	t_rotations	best;
	t_rotations	curr;
	int			i;
	int			size_a;
	int			size_b;
	t_list		*tmp;

	size_a = ft_lstsize(stacks->a);
	size_b = ft_lstsize(stacks->b);
	best.n = INT_MAX;
	i = 0;
	tmp = stacks->b;
	while (tmp)
	{
		curr.ra = get_target_index(*(int *)tmp->content, stacks->a);
		curr.ra = get_rotation(curr.ra, size_a);
		curr.rb = get_rotation(i, size_b);
		curr.n = combined_cost(curr.ra, curr.rb);
		if (curr.n < best.n)
			best = curr;
		i++;
		tmp = tmp->next;
	}
	/* Ejecuta las rotaciones aprovechando movimientos simultáneos */
	while (best.ra > 0 && best.rb > 0)
	{
		rotate(stacks, MOVE_RR);
		best.ra--;
		best.rb--;
	}
	while (best.ra < 0 && best.rb < 0)
	{
		reverse_rotate(stacks, MOVE_RRR);
		best.ra++;
		best.rb++;
	}
	while (best.ra > 0)
	{
		rotate(stacks, MOVE_RA);
		best.ra--;
	}
	while (best.ra < 0)
	{
		reverse_rotate(stacks, MOVE_RRA);
		best.ra++;
	}
	while (best.rb > 0)
	{
		rotate(stacks, MOVE_RB);
		best.rb--;
	}
	while (best.rb < 0)
	{
		reverse_rotate(stacks, MOVE_RRB);
		best.rb++;
	}
}

/*
** final_rotations:
** Una vez que B está vacía, rota la pila A para que el elemento mínimo quede en la cima.
*/
static void	final_rotations(t_stacks *stacks)
{
	int		size_a;
	int		min_idx;
	int		i;
	int		rot;
	t_list	*tmp;
	int		min;

	size_a = ft_lstsize(stacks->a);
	min_idx = 0;
	i = 0;
	tmp = stacks->a;
	min = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
		{
			min = *(int *)tmp->content;
			min_idx = i;
		}
		i++;
		tmp = tmp->next;
	}
	rot = get_rotation(min_idx, size_a);
	while (rot > 0)
	{
		rotate(stacks, MOVE_RA);
		rot--;
	}
	while (rot < 0)
	{
		reverse_rotate(stacks, MOVE_RRA);
		rot++;
	}
}

/*
** b_to_a:
** Mientras haya elementos en la pila B, se selecciona y ejecuta la mejor secuencia
** de rotaciones para trasladar el elemento óptimo a la pila A y se hace push.
** Cuando B queda vacía se hace un ajuste final en A.
*/
void	b_to_a(t_stacks *stacks)
{
	while (stacks->b)
	{
		run_best_rotation_sequence(stacks);
		push(stacks, MOVE_PA);
	}
	final_rotations(stacks);
}
