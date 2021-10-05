#include "utils.h"
#include "operators.h"
#include <stdio.h>

int	ft_parse_op(char *s_op)
{
	if (*s_op == '+')
		return (0);
	if (*s_op == '-')
		return (1);
	if (*s_op == '*')
		return (2);
	if (*s_op == '/')
		return (3);
	if (*s_op == '%')
		return (4);
	return (-1);
}

void	ft_calc_and_print(int n1, int n2, int op_index)
{
	t_op	ops[5];
	int		result;

	ops[0] = &ft_add;
	ops[1] = &ft_subtract;
	ops[2] = &ft_multiply;
	ops[3] = &ft_divide;
	ops[4] = &ft_modulo;
	result = ops[op_index](n1, n2);
	ft_putnbr(result);
	write(1, "\n", 1);
}

void	ft_do_op(char *s1, char *s2, char *s_op)
{
	int	op_index;
	int	n1;
	int	n2;

	op_index = ft_parse_op(s_op);
	if (op_index == -1)
	{
		write(1, "0\n", 2);
		return ;
	}
	n1 = ft_atoi(s1);
	n2 = ft_atoi(s2);
	if (op_index == 3 && n2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	if (op_index == 4 && n2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	ft_calc_and_print(n1, n2, op_index);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	ft_do_op(argv[1], argv[3], argv[2]);
	return (0);
}
