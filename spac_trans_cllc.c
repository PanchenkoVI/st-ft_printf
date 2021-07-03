/*
* Created: 2020/07/31 18:55:03
*/

#include "libftprintf.h"

int			ft_spaces(int len, int *sing)
{
	char	*s1;
	int		i;

	i = 0;
	*sing = -(*sing);
	if (*sing < 0)
		return (0);
	if (!(s1 = (char *)malloc(len + 1)))
	{
		while (len > i)
		{
			s1[i] = 32;
			i++;
		}
		write(1, s1, len);
		free(s1);
		return (len);
	}
	while (i < len)
	{
		write(1, " ", 1);
		i++;
	}
	return (len);
}

int			ft_type_calloc(t_type *flag, long long int *d, int count)
{
	char	*s;
	int		i;
	int		m;

	m = 0;
	i = 0;
	if (*d < 0)
	{
		*d = -(*d);
		m = write(1, "-", 1);
	}
	if (flag->arg == 'p')
		m = write(1, "0x", 2);
	if (!(s = (char *)malloc(count + 1)))
	{
		while (count > i)
			s[i++] = '0';
		write(1, s, count);
		free(s);
		return (count + m);
	}
	while (count > i++)
		write(1, "0", 1);
	return (count + m);
}

int			ft_print_isc(t_type *flag, char *s, long long int m)
{
	if (flag->arg == '%')
		write(1, &m, flag->len);
	else if (flag->arg == 's')
	{
		if (s)
			write(1, s, flag->len);
		else
			write(1, "(null)", flag->len);
	}
	else if (flag->arg == 'd' || flag->arg == 'i')
		ft_trans(m, 0, 'i', flag->len);
	if (flag->arg == 's')
		return (flag->len);
	if (flag->arg == 'i')
		return (flag->len);
	if (flag->arg == 'd')
		return (flag->len);
	if (flag->arg == '%')
		return (flag->len);
	return (0);
}
