/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:19:36 by iait-bel          #+#    #+#             */
/*   Updated: 2021/12/26 14:19:36 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "pushswap.h"


void push(t_stack *st, t_item *item)
{
	if (st->capacity <= st->len)
	{
		ft_putstrfd(2, "Stack is full: can't push\n");
	}
	st->items[st->len].val = item->val;
	st->items[st->len].sort_pos = item->sort_pos;
	st->len++;
}

t_item *pop(t_stack *st)
{
	if (st->len == 0)
	{
		ft_putstrfd(2, "Stack is empty: can't pop\n");
		return 0;
	}
	st->len--;
	return st->items + st->len;
}

int instra_s(t_stack *st)
{
	if (st->len <= 1)
	{
		ft_putstrfd(2, "Stack doesn't have enough elements to swap\n");
		return 0;
	}
	swap(st->items, st->len -1 , st->len - 2);
	return 1;
}

int instra_p(t_stack *st1, t_stack *st2)
{
	t_item *item;

	if (st2->len == 0)
		return 0;
	item = pop(st2);
	push(st1, item);	
	return 1;

}

int instra_r(t_stack *st)
{
	int len;

	len = st->len;
	if (len == 0)
		return 0;
	while(len-- > 1)
	{
		swap(st->items, len, len - 1);
	}
	return 1;
}

int instra_rr(t_stack *st)
{
    int i = 0;
	if (st->len == 0)
		return 0;
	while(i < st->len -1)
	{
		swap(st->items, i, i + 1);
		i++;
	}
	return 1;
}
