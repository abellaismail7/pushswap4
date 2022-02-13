#include "pushswap.h"
#include "stack.h"
#include "common.h"
#include "utils.h"

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

int min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

#include <stdio.h>
int swapif(t_data *data, unsigned int max_pos)
{
	t_stack *stb;
	t_stack *sta;

	sta = &data->sta;
	stb = &data->stb;
	if (stb->len < 2 || sta->len < 2)
		return 0;
	if (stb->items[stb->len - 1].val < stb->items[stb->len - 2].val
		|| sta->items[sta->len - 2].sort_pos >= max_pos)
		return 0;
	swapab(data);
	return 1;
}

int push2b(t_data *data, int div)
{
	int max_pos;
	int count;
	t_stack *sta;
	int sbu = 0;

	sta = &data->sta;
	div = sta->len/div;
	max_pos = sta->len - div;
	count = 0;
	while(sta->len)
	{
		int pos = sta->items[sta->len - 1].sort_pos;
		if (pos >= max_pos)
		{
			if (sbu == 1)
				swipeupb(data);
			sbu = 0;
			pushb(data);
			if (pos >= max_pos + div / 2)
				sbu = 1;
			count++;
			if (count % div == 0)
				max_pos -= div;
		}
		else
		{
			if (sbu == 1)
				swipeup(data);
			//if(!swapif(data, max_pos))
			else
				swipeupa(data);
			sbu = 0;
		}
	}

	return 1;
}

void back2a(t_data *data)
{
	int i;
	t_stack *stb;
	int mpos[2];
	int dis[2];

	stb = &data->stb;
	i = 0;
	while (stb->len)
	{
		find_mins_by_pos(stb, mpos, i);
		dis[0] = min(mpos[0], data->stb.len - mpos[0]);
		dis[1] = min(mpos[1], data->stb.len - mpos[1]);
		if (dis[0] <= dis[1] || mpos[1] == -1)
		{
			bringtoTop(stb, mpos[0], "b");
			pusha(data);
		}
		else
		{
			bringtoTop(stb, mpos[1], "b");
			pusha(data);
			find_mins_by_pos(stb, mpos, i);
			bringtoTop(stb, mpos[0], "b");
			pusha(data);
			swapa(data);
			i++;
		}
		i++;
	}
}

int nextinstra(t_data *data, int div)
{
	push2b(data, div);
	back2a(data);
	//int i = 0;
	//while(i < data->sta.len)
	//{
	//	t_item item = data->sta.items[i];

	//	printf("%d { %d }\n", item.val, item.sort_pos);
	//	i++;
	//}
	return 1;
}
