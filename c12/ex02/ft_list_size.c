#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	if (!begin_list)
		return (0);
	size = 1;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}
