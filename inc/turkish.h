#ifndef TURKISH_H
# define TURKISH_H

typedef struct s_operations
{
	int	ra;
	int	rb;
	int	n;
}	t_operations;

int	location(int n, t_stack **s);
int	operations(t_operations *op);
void	optimize(t_operations *op, int n[2]);
void	print(t_operations op, t_stacks *stacks);
void	rotations(t_operations *op, t_stacks *stacks);

#endif
