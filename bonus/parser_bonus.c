/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:44:38 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/20 12:44:48 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_number(t_stacks *stacks, char *token, char **split)
{
	long	num;
	char	*ptr;
	t_list	*current;

	num = ft_atol(token);
	ptr = token;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	if (!*ptr)
		ft_error(stacks, split);
	while (*ptr)
	{
		if (!ft_isdigit(*ptr++))
			ft_error(stacks, split);
	}
	if (num > INT_MAX || num < INT_MIN)
		ft_error(stacks, split);
	current = stacks->a;
	while (current)
	{
		if (*(int *)(current->content) == num)
			ft_error(stacks, split);
		current = current->next;
	}
	return ((int)num);
}

static void	add_token_to_stack(t_stacks *stacks, char *token, char **split)
{
	int		*value;
	int		num;
	t_list	*node;

	num = check_number(stacks, token, split);
	value = malloc(sizeof(int));
	if (!value)
		ft_error(stacks, split);
	*value = num;
	node = ft_lstnew(value);
	if (!node)
	{
		free(value);
		ft_error(stacks, split);
	}
	ft_lstadd_back(&(stacks->a), node);
}

static void	parse_tokens(t_stacks *stacks, int argc, char **argv)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_error(stacks, NULL);
		j = 0;
		while (split[j])
		{
			add_token_to_stack(stacks, split[j], split);
			j++;
		}
		ft_free_split(split);
		i++;
	}
}

t_stacks	*parser(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(0);
	if (!argv[1] || !*argv[1])
		ft_error(NULL, NULL);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_error(NULL, NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	parse_tokens(stacks, argc, argv);
	stacks->n = ft_lstsize(stacks->a);
	stacks->n_a = stacks->n;
	stacks->n_b = 0;
	return (stacks);
}
