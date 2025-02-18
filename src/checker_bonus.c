/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:21:26 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/18 13:21:34 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	remove_newline(char *instr)
{
	size_t	len;

	len = ft_strlen(instr);
	if (len > 0 && instr[len - 1] == '\n')
		instr[len - 1] = '\0';
}

void	execute_instruction(t_stacks *stacks, char *instr)
{
	if (!ft_strncmp(instr, "sa", 3))
		silent_swap(stacks, MOVE_SA);
	else if (!ft_strncmp(instr, "sb", 3))
		silent_swap(stacks, MOVE_SB);
	else if (!ft_strncmp(instr, "ss", 3))
		silent_swap(stacks, MOVE_SS);
	else if (!ft_strncmp(instr, "pa", 3))
		silent_push(stacks, MOVE_PA);
	else if (!ft_strncmp(instr, "pb", 3))
		silent_push(stacks, MOVE_PB);
	else if (!ft_strncmp(instr, "ra", 3))
		silent_rotate(stacks, MOVE_RA);
	else if (!ft_strncmp(instr, "rb", 3))
		silent_rotate(stacks, MOVE_RB);
	else if (!ft_strncmp(instr, "rr", 3))
		silent_rotate(stacks, MOVE_RR);
	else if (!ft_strncmp(instr, "rra", 4))
		silent_reverse_rotate(stacks, MOVE_RRA);
	else if (!ft_strncmp(instr, "rrb", 4))
		silent_reverse_rotate(stacks, MOVE_RRB);
	else if (!ft_strncmp(instr, "rrr", 4))
		silent_reverse_rotate(stacks, MOVE_RRR);
	else
		ft_error();
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*instr;

	stacks = parser(argc, argv);
	instr = get_next_line(0);
	while (instr)
	{
		remove_newline(instr);
		if (instr[0] == '\0')
		{
			free(instr);
			break ;
		}
		execute_instruction(stacks, instr);
		free(instr);
		instr = get_next_line(0);
	}
	if (check_order(stacks->a) && !(stacks->b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stacks(stacks);
	return (0);
}
