#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*p0;
	t_list	*p1;
	t_list	*p2;

	if (!begin_list || !*begin_list)
		return ;
	p0 = *begin_list;
	p1 = p0->next;
	if (!p1)
		return ;
	p0->next = (void *) 0;
	p2 = p1->next;
	while (p1)
	{
		p1->next = p0;
		p0 = p1;
		p1 = p2;
		if (p2)
			p2 = p2->next;
	}
	*begin_list = p0;
}
