#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*foo;

	foo = malloc(sizeof(t_list));
	if (!foo)
		return (NULL);
	foo->data = data;
	foo->next = NULL;
	return (foo);
}
