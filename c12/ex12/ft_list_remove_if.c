#include "ft_list.h"
#include <stdlib.h>

void	ft_step(t_list **p0, t_list **p1, t_list **p2)
{
	t_list	*pp;

	*p0 = *p1;
	*p1 = *p2;
	pp = *p2;
	if (*p2)
		*p2 = pp->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
}
