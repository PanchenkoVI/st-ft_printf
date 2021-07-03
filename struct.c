/*
* Created: 2020/07/31 18:55:03
*/

#include "libftprintf.h"

static int	ft_type_width(t_type *flag, va_list list, char *s, int i)
{
	int		width;

	width = 0;
	if (s[i] == '*' && i++)
		width = va_arg(list, int);
	while (s[i - 1] != '*' && s[i] >= 48 && s[i] <= 57)
	{
		width = width * 10 + s[i] - 48;
		i++;
	}
	if (width < 0)
	{
		flag->fminus = 1;
		width = -(width);
	}
	flag->width = width;
	return (i);
}

static int	ft_type_precson(t_type *flag, va_list list, char *s, int i)
{
	flag->precsn_set = 1;
	if (s[i] == '*' && i++)
		flag->precision = va_arg(list, int);
	while (s[i - 1] != '*' && s[i] == 48)
		i++;
	while (s[i - 1] != '*' && s[i] >= 48 && s[i] <= 57)
	{
		flag->precision = flag->precision * 10 + s[i] - 48;
		i++;
	}
	if (flag->precision < 0)
	{
		flag->precsn_set = 0;
		flag->precision = 0;
	}
	return (i);
}

static int	ft_sing(t_type *flag, char *s, int i)
{
	while (s[i] == '0' || s[i] == '-')
	{
		while (s[i] == '-')
		{
			if (s[i] == '-')
				flag->fminus = 1;
			i++;
		}
		while (s[i] == '0')
		{
			if (s[i] == '0')
				flag->zero = 1;
			i++;
		}
	}
	return (i);
}

static void	ft_struct_init(t_type *flag)
{
	flag->arg = 0;
	flag->precision = 0;
	flag->width = 0;
	flag->zero = 0;
	flag->parser = 0;
	flag->precsn_set = 0;
	flag->len = 0;
	flag->fminus = -1;
}

int			ft_fstruct(va_list list, t_type *flag, char *s, int i)
{
	i++;
	ft_struct_init(flag);
	i = ft_sing(flag, s, i);
	i = ft_type_width(flag, list, s, i);
	if (s[i] == '.' && i++)
		i = ft_type_precson(flag, list, s, i);
	if (s[i] == 'c')
		flag->arg = s[i];
	else if (s[i] == 's')
		flag->arg = s[i];
	else if (s[i] == 'd' || s[i] == 'i')
		flag->arg = s[i];
	else if (s[i] == 'X' || s[i] == 'x')
		flag->arg = s[i];
	else if (s[i] == 'u')
		flag->arg = s[i];
	else if (s[i] == 'p')
		flag->arg = s[i];
	else if (s[i] == '%')
		flag->arg = s[i];
	return (i + 1);
}
