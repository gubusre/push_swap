/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:34:20 by gubusque          #+#    #+#             */
/*   Updated: 2025/11/16 18:38:30 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int get_pivot(int *arr, int size)
{
    int *copy = malloc(size * sizeof(int));
    if (!copy) return 0;
    for (int i = 0; i < size; i++) copy[i] = arr[i];
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
            if (copy[j] < copy[min_idx])
                min_idx = j;
        int temp = copy[i];
        copy[i] = copy[min_idx];
        copy[min_idx] = temp;
    }
    int pivot = copy[size / 2];
    free(copy);
    return pivot;
}

static void small_sort(t_stacks *s)
{
    if (s->size_a == 2 && s->a[0] > s->a[1])
        sa(s);
    else if (s->size_a == 3) {
        while (!check_is_sorted(s)) {
            if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
                ra(s);
            else if (s->a[1] > s->a[2])
                rra(s);
            else
                sa(s);
        }
    }
}

static void quicksort_rec(t_stacks *s, int size)
{
    if (size <= 3) {
        small_sort(s);
        return;
    }

    int pivot = get_pivot(s->a, size);
    int pushed = 0;

    for (int i = 0; i < size; i++) {
        if (s->a[0] <= pivot) {
            pb(s);
            pushed++;
        } else {
            ra(s);
        }
    }

    for (int i = 0; i < size - pushed; i++)
        rra(s);
    quicksort_rec(s, pushed);
    quicksort_rec(s, size - pushed);
    while (s->size_b > 0)
        pa(s);
}

void ft_push_swap_sort(t_stacks *s)
{
    if (check_is_sorted(s))
        return;
    quicksort_rec(s, s->size_a);
}
