/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_size.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:34:06 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/15 01:22:14 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	size3(t_list *d)
{
	if (d->s_a[0] > d->s_a[1])
		sa(d->s_a);
	if (d->isa == 3)
		if (d->s_a[1] > d->s_a[2])
			rra(d);
	if (d->s_a[0] > d->s_a[1])
		sa(d->s_a);
}



void	s_size(t_list *d)
{
	while (d->isa > 3)
	{
		if (d->s_a[0] < d->maxarg - 3)
			pb(d);
		else
			rra(d);
	}
	if (d->isa <= 3)
		size3(d);
	while (d->isb > 0)
		pa(d);
	if (d->s_a[0] > d->s_a[1])
		sa(d->s_a);
}
