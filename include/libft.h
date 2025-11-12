#ifndef LIBFT_H
#   define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stacks;

int	check_is_valid_number(char *str);
int	check_has_duplicates(int *arr, int size);
int	check_is_sorted(t_stacks *s);
int	ft_atoi(const char *str);
void	ft_push_swap_sort(t_stacks *s);
void	sa(t_stacks *s);
void	sb(t_stacks *s);
void	ss(t_stacks *s);
void	pa(t_stacks *s);
void	pb(t_stacks *s);
void	ra(t_stacks *s);
void	rb(t_stacks *s);
void	rr(t_stacks *s);
void	rra(t_stacks *s);
void	rrb(t_stacks *s);
void	rrr(t_stacks *s);

#endif
