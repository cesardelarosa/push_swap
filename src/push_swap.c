/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpedrer <adpedrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:08:57 by adpedrer          #+#    #+#             */
/*   Updated: 2024/07/26 01:38:26 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	
	stacks_initiator(&a, &b);
	stack_creator(a, argc, argv);
//	order(a, b);
	ft_lstclear_psw(a);
	ft_lstclear_psw(b);	
	free(a);
	free(b);
	return (0);
}


void	error(int i)
{
	if (i == 1)
	{
		ft_putstr_fd("Error ATOI\n", STDERR_FILENO);
		exit(1);
	}
	else if (i == 2)
	{
		ft_putstr_fd("Error listas\n", STDERR_FILENO);
		exit(1);
	}
	else if (i == 3)
	{
		ft_putstr_fd("Error duplicado\n", STDERR_FILENO);
		exit(1);
	}
	else if (i == 5)
	{
		ft_putstr_fd("No estan en orden\n", STDERR_FILENO);
		exit(1);
	}
}

