/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:24:17 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/09 23:08:13 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa_rb(t_list *d)
{
	while (d->isb > 0)
	{
		if (d->s_b[0] == d->lsp - 1)
		{
			pa(d);
			d->control = 1;
		}
		if (d->s_b[0] == d->lsp)
		{
			pa(d);
			d->lsp--;
			if (d->control == 1)
			{
				d->lsp--;
				d->control = 0;
				sa(d->s_a);
			}
		}
		else
			rb(d);
	}
}

void	pb_ra(t_list *d, int i)
{
	while (i >= 0)
	{
		if (d->s_a[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	pa_rb(d);
}


void	small_push_swap(t_list *d)
{
	int	i;
	int	j;

	j = 0;
	i = d->lsp;
	while (d->isb <= (d->argc / 2))
	{
		if (d->s_a[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	pa_rb(d);
	pb_ra(d, i);
}
