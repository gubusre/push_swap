#include "libft.h"

void	ra(t_stacks *s)
{
	int	temp;
	int	i;

	if (s->size_a >= 2)
	{
		temp = s->stack_a[0];
		i = 0;
		while (i < s->size_a - 1)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->stack_a[s->size_a - 1] = temp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stacks *s)
{
	int	temp;
	int	i;

	if (s->size_b >= 2)
	{
		temp = s->stack_b[0];
		i = 0;
		while (i < s->size_b - 1)
		{
			s->stack_b[i] = s->stack_b[i + 1];
			i++;
		}
		s->stack_b[s->size_b - 1] = temp;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stacks *s)
{
	int	temp;
	int	i;
	int	printed;

	if (s->size_a >= 2)
	{
		temp = s->stack_a[0];
		i = 0;
		while (i < s->size_a - 1)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->stack_a[s->size_a - 1] = temp;
		printed = 1;
	}
	if (s->size_b >= 2)
	{
		temp = s->stack_b[0];
		i = 0;
		while (i < s->size_b - 1)
		{
			s->stack_b[i] = s->stack_b[i + 1];
			i++;
		}
		s->stack_b[s->size_b - 1] = temp;
		printed = 1;
	}
	if (printed)
		write(1, "rr\n", 3);
}

void	rra(t_stacks *s)
{
	int	temp;
	int	i;

	if (s->size_a >= 2)
	{
		temp = s->stack_a[s->size_a - 1];
		i = s->size_a - 1;
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = temp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stacks *s)
{
	int	temp;
	int	i;

	if (s->size_b >= 2)
	{
		temp = s->stack_b[s->size_b - 1];
		i = s->size_b - 1;
		while (i > 0)
		{
			s->stack_b[i] = s->stack_b[i - 1];
			i--;
		}
		s->stack_b[0] = temp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stacks *s)
{
	int	temp;
	int	i;
	int	printed;

	if (s->size_a >= 2)
	{
		temp = s->stack_a[s->size_a - 1];
		i = s->size_a - 1;
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = temp;
		printed = 1;
	}
	if (s->size_b >= 2)
	{
		temp = s->stack_b[s->size_b - 1];
		i = s->size_b - 1;
		while (i > 0)
		{
			s->stack_b[i] = s->stack_b[i - 1];
			i--;
		}
		s->stack_b[0] = temp;
		printed = 1;
	}
	write(1, "rrr\n", 4);
}
