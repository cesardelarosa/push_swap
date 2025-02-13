/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:59:07 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/13 19:52:20 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stacks.h"
#include <stdlib.h>
#include <limits.h>

static t_list	*parse_tokens(int argc, char **argv);
static void		add_token_to_stack(t_list **stack, char *token);
static int		check_number(t_list *stack, char *token);
void			ft_error(void);

t_stacks	*parser(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(0);
	if (!argv[1] || !*argv[1])
		ft_error();
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_error();
	stacks->a = parse_tokens(argc, argv);
	stacks->b = NULL;
	stacks->n = ft_lstsize(stacks->a);
	stacks->n_a = stacks->n;
	stacks->n_b = 0;
	return (stacks);
}

static t_list	*parse_tokens(int argc, char **argv)
{
	t_list	*stack;
	char	**split;
	int		i;
	int		j;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_error();
		j = 0;
		while (split[j])
		{
			add_token_to_stack(&stack, split[j]);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (stack);
}

static void	add_token_to_stack(t_list **stack, char *token)
{
	int		*value;
	int		num;
	t_list	*node;

	num = check_number(*stack, token);
	value = malloc(sizeof(int));
	if (!value)
		ft_error();
	*value = (int)num;
	node = ft_lstnew(value);
	if (!node)
		ft_error();
	ft_lstadd_back(stack, node);
}

static int	check_number(t_list *stack, char *token)
{
	long	num;

	num = ft_atol(token);
	if (*token == '-' || *token == '+')
		token++;
	if (!*token)
		ft_error();
	while (*token)
	{
		if (!ft_isdigit(*token++))
			ft_error();
	}
	if (num > INT_MAX || num < INT_MIN)
		ft_error();
	while (stack)
	{
		if (*(int *)(stack->content) == num)
			ft_error();
		stack = stack->next;
	}
	return ((int)num);
}
