/*
* Created: 2020/07/31 18:55:03
*/

#include "libftprintf.h"

static void	ft_hex(long long unsigned int u, int arg, int len)
{
	unsigned int			sing;
	long long unsigned int	div;
	int						count;

	div = 1;
	if (len > 0)
		count = len - 1;
	else
		count = len;
	while (count != 0)
	{
		div = div * 16;
		count--;
	}
	while (len != 0)
	{
		sing = u / div + 48;
		if (u / div > 9)
			sing = (u / div) - 10 + 'a' - ('x' - arg);
		write(1, &sing, 1);
		u = u - (u / div) * div;
		div = div / 16;
		len--;
	}
}

int			ft_print_cxpu(t_type *flag, long long unsigned int m)
{
	if (flag->arg == 'c')
	{
		if (flag->parser == 0)
			write(1, &m, flag->len);
	}
	else if (flag->arg == 'u')
		ft_trans(0, m, 'u', flag->len);
	else if (flag->arg == 'X')
		ft_hex(m, 'X', flag->len);
	else if (flag->arg == 'x')
		ft_hex(m, 'x', flag->len);
	else if (flag->arg == 'p')
		ft_hex(m, 'x', flag->len);
	if (ft_fchar("cuxXp", 5, flag->arg))
		return (flag->len);
	return (0);
}
