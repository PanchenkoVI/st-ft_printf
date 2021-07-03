/*
* Created: 2020/07/31 18:55:03
*/

#include "libftprintf.h"

int			ft_fchar(char *s, int len, char c)
{
	int		i;

	i = 0;
	while (len > i)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_pls_mns(t_type *flag, long long int i)
{
	if (flag->zero > 0)
	{
		flag->precision = flag->precision + flag->width;
		flag->width = 0;
		if (flag->precision > 0)
		{
			if (i < 0)
				flag->precision--;
			if (flag->arg == 'p' && flag->precision > 1)
				flag->precision = flag->precision - 2;
			else if (flag->arg == 'p')
				flag->precision--;
		}
	}
	if (flag->width > 0)
	{
		if (i < 0)
			flag->width--;
		if ((flag->arg == 'p') && flag->width > 1)
			flag->width = flag->width - 2;
		else if (flag->arg == 'p')
			flag->width--;
	}
}

void		ft_width_pres(t_type *flag, long long unsigned u, long long int m)
{
	if (flag->precsn_set > 0 && flag->arg == 's' && flag->precision < flag->len)
	{
		flag->len = flag->precision;
		flag->precision = 0;
	}
	else if (flag->arg == 's')
		flag->precision = 0;
	if (flag->arg == 'c')
		flag->precision = 0;
	if (flag->precision == 0 && flag->precsn_set > 0)
	{
		if ((flag->arg == 'i' || flag->arg == 'd') && m == 0)
			flag->len = 0;
		if (ft_fchar("Xxup", 4, flag->arg) && u == 0)
			flag->len = 0;
	}
	if (flag->precsn_set > 0 && flag->precision > flag->len)
		flag->precision = flag->precision - flag->len;
	else if (!(flag->precsn_set > 0 && flag->precision > flag->len))
		flag->precision = 0;
	if (flag->width > (flag->precision + flag->len))
		flag->width = flag->width - (flag->precision + flag->len);
	else if (!(flag->width > (flag->precision + flag->len)))
		flag->width = 0;
	ft_pls_mns(flag, m);
}

void		ft_replacement(t_type *flag, long long unsigned u, long long int d)
{
	if (flag->arg == 'p' && flag->parser > 0)
		flag->parser = 0;
	if (flag->arg == '%' && flag->parser > 0)
		flag->parser = 0;
	if (ft_fchar("diuxX", 5, flag->arg) && flag->precsn_set > 0)
		flag->zero = 0;
	else if (flag->fminus > 0)
		flag->zero = 0;
	ft_width_pres(flag, u, d);
}
