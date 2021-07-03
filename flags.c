/*
* Created: 2020/07/31 18:55:03
*/

#include "libftprintf.h"

void		ft_flag_s(va_list list, t_type *flag, char **s)
{
	int		i;
	char	*g;

	i = 0;
	*s = 0;
	if (flag->arg == 's')
	{
		*s = (char *)va_arg(list, char *);
		g = *s;
		if (g)
		{
			while (g[i] != 0)
				i++;
			flag->len = i;
		}
		else
			flag->len = 6;
	}
}

static int	ft_divide(long long unsigned int flag_pux, int divisor)
{
	int		i;

	i = 1;
	if (flag_pux / divisor)
	{
		while (flag_pux / divisor)
		{
			i++;
			flag_pux = flag_pux / divisor;
		}
	}
	return (i);
}

void		ft_flag_cpxu(va_list list, t_type *flag, long long unsigned int *f)
{
	long long unsigned int	i;

	i = 0;
	if (flag->arg == 'c')
	{
		i = (unsigned char)va_arg(list, int);
		flag->len = 1;
	}
	else if (flag->arg == 'p')
	{
		i = (long unsigned int)va_arg(list, long);
		flag->len = ft_divide(i, 16);
	}
	else if (flag->arg == 'u' || flag->arg == 'x' || flag->arg == 'X')
	{
		if (flag->parser == 0)
			i = (unsigned int)va_arg(list, int);
		if (flag->parser == 2)
			i = (unsigned char)va_arg(list, int);
		flag->len = ft_divide(i, 16);
		if (flag->arg == 'u')
			flag->len = ft_divide(i, 10);
	}
	*f = i;
}

static int	ft_percent(t_type *flag, long long int i)
{
	i = '%';
	flag->len = 1;
	return (i);
}

void		ft_flag_d_i(va_list list, t_type *flag, long long int *d_i)
{
	long long int	i;
	int				count;
	int				tmp;

	i = 0;
	if (flag->arg == '%')
		*d_i = ft_percent(flag, i);
	else if (flag->arg == 'd' || flag->arg == 'i')
	{
		i = (flag->len == 0) ? (int)va_arg(list, int) : i;
		i = (flag->len == 2) ? (char)va_arg(list, int) : i;
		tmp = i;
		count = 1;
		if (i / 10)
		{
			while (i / 10)
			{
				count++;
				i = i / 10;
			}
		}
		flag->len = count;
		*d_i = (i / 10) ? count : tmp;
	}
}
