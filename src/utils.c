#include "stack.h"
#include "pushswap.h"
#include<stdlib.h>

int append_int(int *res, char c, int sign)
{
	int _num;
	int min;

	if(c < '0' || c > '9')
		return 0;
	_num = *res * 10 - (c - '0');
	min = 1 << 31;
	if(_num > *res || (_num == min && sign == 1))
		return 0;
	*res = _num;
	return 1;
}

int	ft_atoi(char *str, int *res)
{
	int	sign;

	sign = -1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	*res = 0;
	while (*str && append_int(res, *str, sign * -1))
		str++;
	if (*str != 0)
		return 0;
	*res *= sign;
	return 1;
}

void	update_pos(t_item *items, int pos, int size)
{
	int i;
	items[pos].sort_pos = 0;
	i = pos + 1;
	while (i < size)
	{
		if (items[i].val < items[pos].val)
			items[i].sort_pos++;
		else
			items[pos].sort_pos++;
		i++;
	}
}

t_item *av2int(char **av, int size)
{
	t_item	*items;
	int res;
	int i;

	items = malloc(sizeof(t_item) * size);
	if (items == NULL)
		return NULL;
	i = 0;
	while (i < size)
	{
		if(!ft_atoi(av[i], &res))
		{
			free(items);
			return NULL;
		}
		items[size - i - 1].val = res;
		update_pos(items, size - i - 1 , size);
		i++;
	}
	return items;
}

void swap(t_item *arr, int i1, int i2)
{
	t_item tmp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = tmp;
}

