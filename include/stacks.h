/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:56:21 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 09:46:35 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

typedef struct s_operations
{
	int					ra;
	int					rb;
	int					n;
}						t_operations;

typedef struct s_stack	t_stack;

struct					s_stack
{
	t_stack				*prev;
	t_stack				*next;
	int					num;
};

typedef struct s_stacks
{
	t_stack				**stack[2];
	int					n[2];
}						t_stacks;

void					ft_lstadd_back_psw(t_stack **lst, t_stack *new);
t_stack					*ft_lstlast_psw(t_stack *lst);
void					ft_lstadd_front_psw(t_stack **lst, t_stack *new);
t_stack					*ft_lstnew_psw(long content);
void					ft_lstclear_psw(t_stack **lst);

#endif
