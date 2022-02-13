#ifndef PUSHSWAP_H
#define PUSHSWAP_H

typedef struct s_item
{
	int val;
	unsigned int sort_pos;
} t_item;

typedef struct s_stack
{
	int len;
	int capacity;
	unsigned int median;
	t_item *items;
}	t_stack;

typedef struct s_data
{
	int print_inst;
	int size;
	t_stack sta;
	t_stack stb;
} t_data;

int ft_strlen(char *str);
void ft_putstrfd(int fd, char *str);
t_item *av2int(char **av, int size);
void swap(t_item *arr, int i1, int i2);
int nextinstra(t_data *data, int div);
int pushback(t_data *data);
void ft_quicksort(int *arr, int left);
t_item *pop(t_stack *st);

#endif
