#include "libft.h"

void	sa(t_stacks *s)
{
	int	temp;

	if (s->size_a >= 2)
	{
		temp = s->stack_a[0];
		s->stack_a[0] = s->stack_a[1];
		s->stack_a[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stacks *s)
{
	int	temp;

	if (s->size_b >= 2)
	{
		temp = s->stack_b[0];
		s->stack_b[0] = s->stack_b[1];
		s->stack_b[1] = temp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_stacks *s)
{
	int	temp;
	int	printed;

	printed = 0;
	if (s->size_a >= 2)
	{
		temp = s->stack_a[0];
		s->stack_a[0] = s->stack_a[1];
		s->stack_a[1] = temp;
		printed = 1;
	}
	if (s->size_b >= 2)
	{
		temp = s->stack_b[0];
		s->stack_b[0] = s->stack_b[1];
		s->stack_b[1] = temp;
		printed = 1;
	}
	if (printed)
		write(1, "ss\n", 3);
	
}

void	pa(t_stacks *s)
{
	int	i;

	if (s->size_b > 0)
	{
		i = s->size_a;
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = s->stack_b[0];
		s->size_a++;
		i = 0;
		while (i < s->size_b - 1)
		{
			s->stack_b[i] = s->stack_b[i + 1];
			i++;
		}
		s->size_b--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stacks *s)
{
	int	i;

	if (s->size_a > 0)
	{
		i = s->size_b;
		while (i > 0)
		{
			s->stack_b[i] = s->stack_b[i - 1];
			i--;
		}
		s->stack_b[0] = s->stack_a[0];
		s->size_b++;
		i = 0;
		while (i < s->size_a - 1)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->size_a--;
		write(1, "pb\n", 3);
	}
}