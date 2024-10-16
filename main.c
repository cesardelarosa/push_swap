
#include "libft.h"
#include <errno.h>

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
	int		n_a;
	int		n_b;
}	t_stacks;

void	free_stacks(t_stacks *stacks)
{
	ft_lstclear(a, void);
	ft_lstclear(b, void);
	free(a);
	free(b);
	free(stacks);
}

void	error(int status, t_stacks *stacks)
{
	if (stacks != NULL)
		free_stacks(stacks);
	ft_printf("Error\n");
	exit(status);
}

t_stacks	*init_stacks(char **argv)
{
	t_stacks	*stacks;
	int			n;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		error(ENOMEM, NULL);
	stacks.a = malloc(sizeof(t_list));
	if (stacks.a == NULL)
		error(ENOMEM, stacks);
	if (stacks.b == NULL)
		error(ENOMEM, stacks);
	while (argv++)
	{
		if (*argv == NULL)
			error(1)
		n = ft_atoi(*argv);
		while (*argv)
		{
			if (ft_isdigit(*argv++) == 0)
				error(1);
		}
		while (stacks->a)
		{
			if (stacks->a->content == n)
				error(1);
		}
		ft_lstadd_back(stacks.a, ft_lstnew(n));
	}
	return (stacks);
}
/*
void	order(t_stacks *stacks)
{
	a_to_b(stacks);
	b_to_a(stacks);
	final_order(stacks);
}
*/
void	print_content(void	*content)
{
	if (content)
		printf("%d\n", (int)content);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_stacks(argv);
//	order(stacks);
	ft_lstiter(stacks->a, print_content);
	free_stacks(stacks);
	return (0);
}
