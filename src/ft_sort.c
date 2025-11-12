#include "libft.h"

void print_stacks(t_stacks *s)
{
    printf("stack_a: ");
    for (int i = 0; i < s->size_a; i++)
        printf("%d ", s->stack_a[i]);
    printf("\nstack_b: ");
    for (int i = 0; i < s->size_b; i++)
        printf("%d ", s->stack_b[i]);
    printf("\n");
}

static void	ft_sort_small(t_stacks *s)
{
	if (s->size_a == 2)
	{
		if (s->stack_a[0] > s->stack_a[1])
			sa(s);
	}
	else if (s->size_a == 3)
	{
		while (!check_is_sorted(s))
		{
			if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
				ra(s);
			else if (s->stack_a[1] > s->stack_a[0] && s->stack_a[1] > s->stack_a[2])
				rra(s);
			else
				sa(s);
		}
	}
}

static int	get_median(int *arr, int size)
{
	int	*sorted;
	int	i;
	int	j;
	int	temp;

	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return (0);
	i = 0;
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	temp = sorted[size / 2];
	free(sorted);
	return (temp);
}

static void partition_stack(t_stacks *s, int size)
{
    int pivot;
    int count;
    int i;

    if (size <= 3)
    {
        ft_sort_small(s);
        return ;
    }
    pivot = get_median(s->stack_a, size);
    count = 0;
    i = 0;
    while (i < size)
    {
        if (s->stack_a[0] < pivot)
        {
            pb(s);
            count++;
        }
        else
            ra(s);
        i++;
    }
    i = 0;
    while (i < size - count)
    {
        rra(s);
        i++;
    }
}

void	ft_push_swap_sort(t_stacks *s)
{
	int	partition_size;

	while (!check_is_sorted(s))
	{
		if (s->size_a <= 3)
		{
			ft_sort_small(s);
			while (s->size_b > 0)
				pa(s);
		}
		else
		{
			partition_size = s->size_a;
			print_stacks(s);
			partition_stack(s, partition_size);
		}
	}
}
