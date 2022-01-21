#include "pushswap.h"
#include "stack.h"
#include "common.h"
#include <sys/_types/_sigaltstack.h>

int bringtoTop(t_stack *st, int pos, char * str)
{
	int mv;

	if (pos == st->len - 1)
		return 0;
	if(pos + 2 == st->len)
	{
		ft_putstrfd(1, "s");
		ft_putstrfd(1, str);
		ft_putstrfd(1, "\n");
		instra_s(st);
		return 1;

	}
	if (pos >= st->len / 2)
	{
		mv = st->len - pos - 1;
		while(mv--)
		{
			ft_putstrfd(1, "r");
			ft_putstrfd(1, str);
			ft_putstrfd(1, "\n");
			instra_r(st);
		}
	}
	else
	{
		mv = pos + 1;
		while(mv--)
		{
			ft_putstrfd(1, "rr");
			ft_putstrfd(1, str);
			ft_putstrfd(1, "\n");
			instra_rr(st);
		}
	}
	return 1;
}

unsigned int biggest_top(t_stack *st)
{
	int i;
	int pos;

	pos = st->len - 1;
	
	i = 0;
	while(i < st->len - 1)
	{
		if (st->items[pos].val < st->items[i].val)
			pos = i;
		i++;
	}
	bringtoTop(st, pos, "b");
	return 1;
}

int pushback(t_data *data)
{
	int i;
	
	i = 0;
	while (data->stb.len)
	{
		biggest_top(&data->stb);
		pusha(data);
		i++;
	}
	return (i);
}


int min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

void swapbif(t_data *data)
{
	t_stack *st;

	st = &data->stb;
	if (st->len < 2)
		return ;
	if (st->items[st->len - 1].sort_pos > st->items[0].sort_pos)
		swipeupb(data);
	else if (st->items[st->len - 1].val < st->items[st->len - 2].val)
		swapb(data);
}

void sorta(t_data *data)
{
	while(data->sta.len)
		pushb(data);
}

int nextinstra(t_data *data)
{
	unsigned int half;
	int j;

	half = data->sta.median;
	while(data->sta.len > 4)
	{
		j = 0;
		while (j < 4)
		{
			if (data->sta.items[data->sta.len - 1].sort_pos >= half)
			{
				pushb(data);
				swapbif(data);
			}
			else
			{
				swipeupa(data);
				continue;
			}
			j++;
		}
		half -= 2;
	}
	sorta(data);
	return 1;
}
