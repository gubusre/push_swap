/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:41:49 by gubusque          #+#    #+#             */
/*   Updated: 2025/10/22 16:31:03 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_count_sort_0(int stack_a[], int n)
{
	int	maxval;
	int	n;
	int	i;

	maxval = 0;
	i = -1;
	n = (sizeof(stack_a) / sizeof(stack_a[0]));
	while (++i < n)
	{
		if(arr[i] > maxval)
			maxval = arr[i];
	}
	ft_count_sort_1(arr, n, maxval);
}

void	ft_count_sort_1(int stack_a[], int n, int maxval)
{
	int	stack_aux[];
	int	stabk_b[];
	int	i;
	int	pos;
	i = -1;
	stack_b = (int*)ft_calloc(maxval + 1, sizeof(int));
	while(++i < n)
		stack_aux[arr[i]] = 1;
	pos = 0;
	i = -1;
	while (++i <= maxval)
	{
		if(stack_aux[i] == 1)
			stack_b[pos++] = i;
	}
	i = -1;
	while (++i < n)
		stack_a[i] = stack_b;
	free(stack_aux);
	free(stack_b);
}
