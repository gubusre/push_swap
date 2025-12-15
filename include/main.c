/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:50:48 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/15 18:42:49 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_size(t_list *d)
{
	d->maxarg = d->argc;
	d->control = 0;
	d->blocks = 0;
	d->chunk = 1;
	d->lsp = d->argc - 1;
	bubble_sort(d);
	ft_index(d);
	if (d->maxarg <= 5)
		s_size(d);
	else if (d->maxarg < 20 && d->maxarg > 5)
		d->blocks = 1;
	else if (d->maxarg < 101 && d->maxarg > 19)
		d->blocks = 5;
	else if (d->maxarg > 100)
		d->blocks = 10;
	if (d->blocks > 0)
		push_swap(d);
}

static int	ft_stack(t_list *d, char *argv[])
{
	int	i;

	i = 0;
	while (i != d->argc)
	{
		d->s_a[i] = ft_atoi(argv[i + 1], d);
		if (d->atoierror == 1)
			return (-1);
		d->s_s[i] = d->s_a[i];
		i++;
	}
	if (check_order(d) == -1)
		return (-1);
	if (check_same_nums(d) == -1)
		return (-1);
	return (0);
}

static int	ft_data(t_list *d, char *argv[])
{
	d->s_a = malloc(sizeof(int) * d->argc);
	d->s_b = malloc(sizeof(int) * d->argc);
	d->s_s = malloc(sizeof(int) * d->argc);
	if (!d->s_a || !d->s_b || !d->s_s)
		return (-1);
	d->isa = d->argc;
	d->isb = 0;
	d->iss = d->argc;
	d->blocks = 0;
	if (ft_stack(d, argv) == -1)
		return (-1);
	return (0);
}

int	main(int arc, char *argv[])
{
	t_list	*d;

	if (arc == 1)
		return (0);
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	d->s_a = NULL;
	d->s_b = NULL;
	d->s_s = NULL;
	d->argc = arc - 1;
	d->error = 0;
	if (check_args(argv, d->argc) == -1)
		ft_efree(d);
	if (ft_data(d, argv) == -1)
		ft_efree(d);
	ft_size(d);
	ft_free(d);
	return (0);
}
