/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:43:35 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/04 22:25:34 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

void	swap(t_stacks *stacks, char c);
void	push(t_stacks *stacks, char c);
void	rotate(t_stacks *stacks, char c);
void	reverse_rotate(t_stacks *stacks, char c);

void	order(t_stacks *stacks);

#endif
