#ifndef STACK_H
#define STACK_H
#include "pushswap.h"

t_item *pop(t_stack *st);
void push(t_stack *st, t_item *item);
int instra_s(t_stack *st);
int instra_p(t_stack *st1, t_stack *st2);
int instra_r(t_stack *st);
int instra_rr(t_stack *st);

#endif // !STACK_H

