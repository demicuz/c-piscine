#ifndef OPERATORS_H
# define OPERATORS_H

typedef int	(*t_op)(int, int);

int	ft_add(int a, int b);
int	ft_subtract(int a, int b);
int	ft_multiply(int a, int b);
int	ft_divide(int a, int b);
int	ft_modulo(int a, int b);

#endif