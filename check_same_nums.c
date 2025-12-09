/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_same_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:57:30 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/09 21:58:22 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	int	ft_compare(t_list *d, int num, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (d->s_a[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_same_nums(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->isa - 1)
	{
		if (ft_compare(d, d->s_a[i], i) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}
