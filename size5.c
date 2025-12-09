/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:34:06 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/09 23:03:14 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	size4(int *s, t_list *d)
{
	if (d->isa == 4)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && d->isa == 4)
			pb(d);
		if (s[0] > s[1] && s[1] < s[2] && s[1] < s[3] && d->isa == 4)
		{
			sa(d->s_a);
			pb(d);
		}
		if (s[0] > s[2] && s[1] > s[2] && s[2] < s[3] && d->isa == 4)
		{
			ra(d);
			sa(d->s_a);
			pb(d);
		}
		if (s[0] > s[3] && s[1] > s[3] && s[2] > s[3] && d->isa == 4)
		{
			rra(d);
			pb(d);
		}
	}
	if (d->isa == 3)
		size3(d->s_a, d);
	pa(d);
}

int	size5_2(int *s, t_list *d, int i)
{
	if (s[0] > s[2] && s[1] > s[2] && s[2] < s[3] && s[2] < s[4] && i == 0)
	{
		ra(d);
		sa(d->s_a);
		pb(d);
		i++;
	}
	if (s[0] > s[3] && s[1] > s[3] && s[2] > s[3] && s[3] < s[4] && i == 0)
	{
		rra(d);
		rra(d);
		pb(d);
		i++;
	}
	if (s[0] > s[4] && s[1] > s[4] && s[2] > s[4] && s[3] > s[4] && i == 0)
	{
		rra(d);
		pb(d);
		i++;
	}
	return (i);
}

void	size5(int *s, t_list *d)
{
	int	i;

	i = 0;
	if (d->isa == 5)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && s[0] < s[4] && i == 0)
		{
			pb(d);
			i++;
		}
		if (s[0] > s[1] && s[1] < s[2] && s[1] < s[3] && s[1] < s[4] && i == 0)
		{
			sa(d->s_a);
			pb(d);
			i++;
		}
		i = size5_2(d->s_a, d, i);
	}
	size4(d->s_a, d);
	if (i == 1)
	{
		pa(d);
		if (s[0] > s[1])
			sa(d->s_a);
	}
}
