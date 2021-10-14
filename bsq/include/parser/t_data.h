#ifndef T_DATA_H
# define T_DATA_H

typedef struct s_data
{
	unsigned int	w;
	unsigned int	h;
	// unsigned int 	x;
	// unsigned int 	y;
	// unsigned int 	max;
	char			free;
	char			obst;
	char 			full;
	char			**field;
	unsigned int	current_row;
} t_data;

#endif