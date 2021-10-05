#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*prev;

	prev = begin_list;
	while (begin_list)
	{
		if (begin_list->data)
			free_fct(begin_list->data);
		begin_list = begin_list->next;
		free(prev);
		prev = begin_list;
	}
}
