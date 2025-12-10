/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:31:27 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/10 23:40:31 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	calc(t_list *d)
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
		if (d->control == 2)
		{
			d->lsp = d->lsp - 2;
			d->control = 0;
			sa(d->s_a);
			rra(d);
		}
	}
	else
		rb(d);
}

int	check_mov(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->isb - 1)
	{
		if (d->s_b[i] == d->lsp)
			break ;
		i++;
	}
	if ((d->isb / 2) - i >= 0)
		return (0);
	else
		return (-1);
}

void	ordernums_sb_rotate(t_list *d)
{
	if (d->s_b[0] == d->lsp -2 && d->control == 1)
	{
		pa(d);
		ra(d);
		d->control = 2;
	}
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
		rrb(d);
}

void	ordernums_sb(t_list *d)
{
	while (d->isa < d->argc)
	{
		if (d->s_b[0] == d->lsp && d->control == 0)
		{
			pa(d);
			d->lsp--;
		}
		if (d->s_b[0] == d->lsp -2 && d->control == 1)
		{
			pa(d);
			ra(d);
			d->control = 2;
		}
		if (check_mov(d) == -1)
			ordernums_sb_rotate(d);
		else
			calc(d);
	}
}

void	push_swap(t_list *d)
{
	d->chunk_size = (d->argc / d->blocks) * (d->chunk);
	if (d->chunk == d->blocks)
		d->chunk_size = d->maxarg - 3;
	while (d->isb < d->chunk_size && d->chunk <= d->blocks)
	{
		if (d->s_a[0] < d->chunk_size)
		{
			pb(d);
			if (d->s_b[0] > d->chunk_size - d->size_block && d->isb > 1)
				rb(d);
		}
		else
			ra(d);
	}
	d->chunk++;
	if (d->isb == d->maxarg - 3)
	{
		size3(d->s_a, d);
		d->lsp = d->lsp - 3;
	}
	if (d->chunk <= d->blocks)
		push_swap(d);
	while (d->chunk-- > 0)
		ordernums_sb(d);
}
