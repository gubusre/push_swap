#include "libft.h"

int	main(int argc, char *argv[])
{
	t_stacks	s;
	int			i;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	s.size_a = argc - 1;
	s.size_b = 0;
	s.stack_a = malloc(s.size_a * sizeof(int));
	s.stack_b = malloc(s.size_a * sizeof(int));
	if (!s.stack_a || !s.stack_b)
		return (1);
	i = 0;
	while (i < s.size_a)
	{
		if (!check_is_valid_number(argv[i + 1]))
		{
			write(2, "Error\n", 6);
			free(s.stack_a);
			free(s.stack_b);
			return (1);
		}
		s.stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (check_has_duplicates(s.stack_a, s.size_a))
	{
		write(2, "Error\n", 6);
		free(s.stack_a);
		free(s.stack_b);
		return (1);
	}
	if (!check_is_sorted(&s))
		ft_count_sort_0(&s);
	free(s.stack_a);
	free(s.stack_b);
	return (0);
}
