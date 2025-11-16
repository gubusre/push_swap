/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:41:12 by gubusque          #+#    #+#             */
/*   Updated: 2025/11/16 18:41:14 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void sa(t_stacks *s) {
    int temp;
    if (s->size_a >= 2) {
        temp = s->a[0]; s->a[0] = s->a[1]; s->a[1] = temp;
        write(1, "sa\n", 3);
    }
}

void sb(t_stacks *s) {
    int temp;
    if (s->size_b >= 2) {
        temp = s->b[0]; s->b[0] = s->b[1]; s->b[1] = temp;
        write(1, "sb\n", 3);
    }
}

void ss(t_stacks *s) {
    int did_a = 0, did_b = 0;
    int temp;
    if (s->size_a >= 2) {
        temp = s->a[0]; s->a[0] = s->a[1]; s->a[1] = temp;
        did_a = 1;
    }
    if (s->size_b >= 2) {
        temp = s->b[0]; s->b[0] = s->b[1]; s->b[1] = temp;
        did_b = 1;
    }
    if (did_a && did_b)
        write(1, "ss\n", 3);
}

void pa(t_stacks *s) {
    if (s->size_b <= 0) return;
    for (int i = s->size_a; i > 0; i--)
        s->a[i] = s->a[i - 1];
    s->a[0] = s->b[0];
    s->size_a++;
    for (int i = 0; i < s->size_b - 1; i++)
        s->b[i] = s->b[i + 1];
    s->size_b--;
    write(1, "pa\n", 3);
}

void pb(t_stacks *s) {
    if (s->size_a <= 0) return;
    for (int i = s->size_b; i > 0; i--)
        s->b[i] = s->b[i - 1];
    s->b[0] = s->a[0];
    s->size_b++;
    for (int i = 0; i < s->size_a - 1; i++)
        s->a[i] = s->a[i + 1];
    s->size_a--;
    write(1, "pb\n", 3);
}

void ra(t_stacks *s) {
    int temp, i;
    if (s->size_a < 2) return;
    temp = s->a[0];
    for (i = 0; i < s->size_a - 1; i++)
        s->a[i] = s->a[i + 1];
    s->a[s->size_a - 1] = temp;
    write(1, "ra\n", 3);
}

void rb(t_stacks *s) {
    int temp, i;
    if (s->size_b < 2) return;
    temp = s->b[0];
    for (i = 0; i < s->size_b - 1; i++)
        s->b[i] = s->b[i + 1];
    s->b[s->size_b - 1] = temp;
    write(1, "rb\n", 3);
}

void rr(t_stacks *s) {
    int did_a = 0, did_b = 0;
    int temp, i;
    if (s->size_a >= 2) {
        temp = s->a[0];
        for (i = 0; i < s->size_a - 1; i++) s->a[i] = s->a[i + 1];
        s->a[s->size_a - 1] = temp;
        did_a = 1;
    }
    if (s->size_b >= 2) {
        temp = s->b[0];
        for (i = 0; i < s->size_b - 1; i++) s->b[i] = s->b[i + 1];
        s->b[s->size_b - 1] = temp;
        did_b = 1;
    }
    if (did_a && did_b)
        write(1, "rr\n", 3);
}

void rra(t_stacks *s) {
    int temp, i;
    if (s->size_a < 2) return;
    temp = s->a[s->size_a - 1];
    for (i = s->size_a - 1; i > 0; i--)
        s->a[i] = s->a[i - 1];
    s->a[0] = temp;
    write(1, "rra\n", 4);
}

void rrb(t_stacks *s) {
    int temp, i;
    if (s->size_b < 2) return;
    temp = s->b[s->size_b - 1];
    for (i = s->size_b - 1; i > 0; i--)
        s->b[i] = s->b[i - 1];
    s->b[0] = temp;
    write(1, "rrb\n", 4);
}

void rrr(t_stacks *s) {
    int did_a = 0, did_b = 0;
    int temp, i;
    if (s->size_a >= 2) {
        temp = s->a[s->size_a - 1];
        for (i = s->size_a - 1; i > 0; i--) s->a[i] = s->a[i - 1];
        s->a[0] = temp;
        did_a = 1;
    }
    if (s->size_b >= 2) {
        temp = s->b[s->size_b - 1];
        for (i = s->size_b - 1; i > 0; i--) s->b[i] = s->b[i - 1];
        s->b[0] = temp;
        did_b = 1;
    }
    if (did_a && did_b)
        write(1, "rrr\n", 4);
}
