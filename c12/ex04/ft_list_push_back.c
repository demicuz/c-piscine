#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*p;

	if (!begin_list)
		return ;
	elem = ft_create_elem(data);
	if (!elem)
		return ;
	p = *begin_list;
	if (!p)
	{
		*begin_list = elem;
		return ;
	}
	while (p && p->next)
		p = p->next;
	p->next = elem;
}
