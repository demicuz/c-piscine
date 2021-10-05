#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	if (!begin_list)
		return ;
	elem = ft_create_elem(data);
	if (!elem)
		return ;
	elem->next = *begin_list;
	*begin_list = elem;
}

t_list	*ft_list_push_strs(int size, char **str)
{
	t_list	*l;
	int		i;

	l = (void *) 0;
	i = 0;
	while (i < size)
	{
		ft_list_push_front(&l, str[i]);
		i++;
	}
	return (l);
}
