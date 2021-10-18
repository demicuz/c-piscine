#include <stdio.h>

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "main.h"

//TODO remove all puts and printf

void	ft_solve_and_print(t_data *d)
{

}

int	ft_read_line(int fd, char *buffer, int size)
{
	int		i;
	int		ret;

	if (!buffer)
		return (0);
	i = 0;
	ret = read(fd, buffer, 1);
	while (ret >= 0 && i < size)
	{
		if (buffer[i] == '\n')
			break ;
		else if (buffer[i] == '\0')
			return (0);
		i++;
		ret = read(fd, buffer + i, 1);
	}
	if (buffer[i] != '\n')
		return (0);
	buffer[i] = '\0';
	printf("chars in line read: %d\n", i);
	return (i);
}

int	ft_check_data(t_data *d)
{
	printf("%c\n", d->free);
	printf("%c\n", d->obst);
	printf("%c\n", d->full);
	return (0);
	return (d->h > 0 && ft_char_is_printable(d->free)
	        && ft_char_is_printable(d->obst) && ft_char_is_printable(d->full)
	        && d->free != d->obst && d->free != d->full && d->obst != d->full);
}

int	ft_parse_map_data(char *str, t_data *d)
{
	unsigned int	h;
	char			*data_start;

	data_start = str;
	h = ft_atoi_unsigned(str);
	if (h == 0)
		return (0);
	str = ft_skip_atoi(str);
	if (ft_strlen(str) < 3)
		return (0);
	d->h = h;
	d->free = str[0];
	d->obst = str[1];
	d->full = str[2];
	d->field = malloc(sizeof(char *) * h);
	if (!(d->field))
		return (0);
	d->current_row = 0;
	return (1);
}

void	ft_free_field(t_data *d)
{
	if (d->field)
	{
		while (d->current_row > 0)
		{
			printf("Freeing %s\n", d->field[d->current_row - 1]);
			free(d->field[d->current_row - 1]);
			d->current_row--;
		}
		free(d->field);
	}
}

void	ft_free_data(t_data *d)
{
	if (d)
	{
		ft_free_field(d);
		free(d);
		printf("%s\n", "Data freed successfully");
	}
}

int	ft_read_and_check_row(t_data *d, int fd, int row_len)
{
	char	*row;
	int		this_len;

	row = malloc(sizeof(char) * (row_len + 1));
	d->field[d->current_row] = row;  // free() shoots us in the leg otherwise
	if (!row)
		return (0);
	this_len = ft_read_line(fd, row, row_len);

	return (this_len);
}

// t_data *d has all the data about the map
int	ft_read_and_check_map(t_data *d, int fd)
{
	int	row_len;
	int	row_read;

	d->current_row = 0;
	row_len = ft_read_and_check_row(d, fd, FIVE_MEGS);
	d->current_row++;
	if (row_len == 0)
		return (0);
	while (d->current_row < d->h)
	{
		row_read = ft_read_and_check_row(d, fd, row_len);
		printf("current row len: %d\n", row_read);
		d->current_row++;
		if (!row_read || row_read != row_len)
			return (0);
	}
	return (1);
}

void	ft_process_one_file(int fd, t_data *d)
{
	char	*first_line;

	first_line = malloc(sizeof(char) * BUF_SIZE);
	if (ft_read_line(fd, first_line, BUF_SIZE) <= 0)
	{
		puts("map error");
		return ;
	}
	ft_parse_map_data(first_line, d);
	free(first_line);
	if (!ft_check_data(d))
		puts("map error");
	else
	{
		if (ft_read_and_check_map(d, fd))
			ft_solve_and_print(d);
		else
			puts("map error");
	}
	ft_free_field(d);
}

t_data	*ft_init_data()
{
	t_data *d;

	d = malloc(sizeof(t_data));
	d->field = NULL;
	return d;
}

void	ft_process_files(int count, char *names[])
{
	int		fd;
	int		i;
	t_data	*d;

	i = 0;
	d = ft_init_data();
	// if (!d)
	// {
	// 	puts("map error");
	// 	return ;
	// }
	while (i < count)
	{
		fd = open(names[i], O_RDONLY);
		if (fd == -1)
			puts("map error");
		else
		{
			ft_process_one_file(fd, d);
			close(fd);
		}
		i++;
	}
	ft_free_data(d);
}

// char **ft_check_and_save_map(int fd)
// {

// }

int	main(int argc, char *argv[])
{
	if (argc >= 2)
		ft_process_files(argc - 1, argv + 1);
	else
		puts("No arguments, should read the standard input");

	// char **map = ft_check_and_save_map(fd);
	return (0);
}
