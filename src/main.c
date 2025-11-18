/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:36:01 by gubusque          #+#    #+#             */
/*   Updated: 2025/11/17 15:50:55 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char *argv[])
{
	t_stacks s = {0};
	int	i;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	s.size_a = argc - 1;
	s.a = malloc(s.size_a * sizeof(int));
	s.b = malloc(s.size_a * sizeof(int));
	if (!s.a || !s.b)
		return (1);
	i = 0;
	while (i < s.size_a)
	{
		if (!check_is_valid_number(argv[i + 1]))
		{
			write(2, "Error\n", 6);
			free(s.a);
			free(s.b);
			return (1);
		}
		s.a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (check_has_duplicates(s.a, s.size_a))
	{
		write(2, "Error\n", 6);
		free(s.a);
		free(s.b);
		return (1);
	}
	ft_push_swap_sort(&s);
	free(s.a);
	free(s.b);
	return (0);
}
