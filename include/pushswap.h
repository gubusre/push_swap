/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:14:29 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/15 18:55:47 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int	*s_a;
	int	*s_b;
	int	*s_s;
	int	isa;
	int	isb;
	int	iss;
	int	argc;
	int	lsp;
	int	control;
	int	chunk;
	int	chunk_lsp;
	int	blocks;
	int	size_block;
	int	maxarg;
	int	atoierror;
	int	error;
}	t_list;

int		main(int arc, char **argv);
int		check_args(char **args, int argc);
int		check_num(char *s);
int		ft_strlen(char *s);
int		ft_atoi(const char *s, t_list *d);
int		check_order(t_list *d);
int		check_same_nums(t_list *d);
void	bubble_sort(t_list *d);
void	ft_swap(int *argv1, int *argv2);
void	ft_index(t_list *d);
void	s_size(t_list *d);
void	ft_sort(t_list *d);
void	push_swap(t_list *d);
void	pa(t_list *d);
void	pb(t_list *d);
void	sa(int *s_a);
void	sb(int *s_b);
void	ss(t_list *d);
void	rra(t_list *d);
void	rrb(t_list *d);
void	ra(t_list *d);
void	rb(t_list *d);
void	rr(t_list *d);
void	rrr(t_list *d);
void	rrr(t_list *d);
void	ft_efree(t_list *d);
void	ft_free(t_list *d);

#endif
