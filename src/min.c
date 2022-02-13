#include "pushswap.h"

unsigned int find_min(t_stack *st, unsigned int pos)
{
	int i;

	i = 0;
	while(i < st->len)
	{
		if (st->items[i].sort_pos == pos)
			return i;
		i++;
	}
	return 0;
}

void find_mins(t_stack *st, int mpos[])
{
	int i;
	mpos[0] = 0;
	mpos[1] = 0;
	i = 0;
	while(i < st->len)
	{
		if (st->items[i].val < st->items[mpos[0]].val)
		{
			mpos[1] = mpos[0];
			mpos[0] = i;
		}
		else if (st->items[i].val < st->items[mpos[1]].val)
			mpos[1] = i;
		i++;
	}
}


void find_mins_by_pos(t_stack *st, int *mpos, unsigned int pos)
{
	int i;
	mpos[0] = -1;
	mpos[1] = -1;
	i = 0;
	while(i < st->len)
	{
		if (mpos[0] == -1 && st->items[i].sort_pos == pos)
			mpos[0] = i;
		else if (mpos[1] == -1 && st->items[i].sort_pos == pos + 1)
			mpos[1] = i;
		i++;
	}
}
