/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:31:27 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/15 19:06:07 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_block_b(t_list *d, int x)
{
	int	i;

	i = 0;
	while (i < d->isb)
	{
		if (d->s_b[i] == d->lsp)
			break;
		i++;
	}
	if (i > (x / 2))
		return (1);
	return (-1);
}

int	check_block_a(t_list *d, int x)
{
	int	i;

	i = 0;
	while (i < d->isa)
	{
		if (d->s_a[i] <= d->chunk_lsp)
			break ;
		i++;
	}
	if (i >= (x / 2))
		return (1);
	return (-1);
}

void	ft_pa(t_list *d)
{
	int	i;

	i = 0;
	if (d->s_b[0] == d->lsp - 1)
	{
		pa(d);
		d->control = 1;
	}
	/*printf("d->lsp= %d\n", d->lsp);
	printf("sb[0]= %d\n", d->s_b[0]);
	printf("isb =  %d\n", d->isb);
	printf("sa[0]= %d\n", d->s_a[0]);*/
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
		i = check_block_b(d, d->isb);
	if (i > 0 && d->lsp > 0)
		rrb(d);
	if (i < 0 && d->lsp > 0)
		rb(d);
	if (d->isb > 0 && d->isa < d->maxarg)
		ft_pa(d);
}

void	push_swap(t_list *d)
{
	int	i;

	i = 0;
	d->size_block = d->argc / d->blocks;
	d->chunk_lsp = ((d->argc * d->chunk) * d->blocks);
	while (d->isb < d->chunk_lsp && d->chunk <= d->blocks)
	{
		if (d->s_a[0] <= d->chunk_lsp)
		{
			//printf("sa[0]= %d\n", d->s_a[0]);
			//printf("isb= %d\n", d->isb);
			pb(d);
			if (d->s_b[0] > d->chunk_lsp - d->size_block && d->isb > 1)
				rb(d);
			if (d->s_b[0] < d->s_b[1] && d->isb > 1)
			{
				if (d->s_a[0] > d->s_a[1])
					ss(d);
				else
					sb(d->s_b);
			}
		}
		else
			i = check_block_a(d, d->isa);
		if (i > 0)
		{
			//printf("sa[0]= %d\n", d->s_a[0]);
			rra(d);
		}
		if (i < 0)
		{
			//printf("sa[0]= %d\n", d->s_a[0]);
			ra(d);
		}
	}
	d->chunk++;
	if (d->blocks >= d->chunk)
		push_swap(d);
	ft_pa(d);
}
