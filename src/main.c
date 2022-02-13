#include "pushswap.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void iquicksort(int *arr, int *iarr, int left);
int *incarr(int size);

t_stack stack_wrap(t_item *items, int cap, int len)
{
	t_stack st;

	st.items = items;
	st.len = cap;
	st.capacity = len;
	return st;
}

void ft_pushswap(t_data *data)
{
	if (data->sta.len > 200)
		nextinstra(data, 10);	
	else if (data->sta.len > 50)
		nextinstra(data, 5);	
	else
		nextinstra(data, 4);	
}

int data_setup(int size, char **av)
{
	t_data data;

	data.print_inst = 1;
	data.sta = stack_wrap(av2int(av, size), size, size);
	data.sta.median = data.sta.len / 2;
	data.stb = stack_wrap(malloc(sizeof(t_item) * size), 0, size);
	if (data.sta.items == 0 ||  data.stb.items == 0)
	{
		free(data.sta.items);
		free(data.stb.items);
		ft_putstrfd(2, "ERROR\n");
		return 1;
	}
	ft_pushswap(&data);
	free(data.sta.items);
	free(data.stb.items);
	return 0;
}

int main(int ac, char **av)
{
	return (data_setup(ac - 1, av + 1));
}
