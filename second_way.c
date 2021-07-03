/*
* Created: 2020/07/31 18:55:03
*/

#include "libftprintf.h"

int	ft_core(va_list list, char *str, int *i, int symbol)
{
	int						step;
	t_type					flag;
	char					*s;
	long long int			d;
	unsigned long long int	cpxu;

	step = ft_fstruct(list, &flag, str, *i);
	ft_flag_d_i(list, &flag, &d);
	ft_flag_s(list, &flag, &s);
	ft_flag_cpxu(list, &flag, &cpxu);
	ft_replacement(&flag, cpxu, d);
	symbol = symbol + ft_spaces(flag.width, &flag.fminus);
	symbol = symbol + ft_type_calloc(&flag, &d, flag.precision);
	symbol = symbol + ft_print_isc(&flag, s, d);
	symbol = symbol + ft_print_cxpu(&flag, cpxu);
	symbol = symbol + ft_spaces(flag.width, &flag.fminus);
	*i = step;
	return (symbol);
}

int	ft_cycle(va_list list, const char *str, int symbol)
{
	int		i;
	int		shift;
	char	*s;

	i = 0;
	shift = 0;
	s = (char *)str;
	while (s[i] != '\0' && symbol >= 0)
	{
		if (s[i] == '%')
		{
			symbol = symbol + write(1, &s[shift], i - shift);
			symbol = ft_core(list, s, &i, symbol);
			shift = i;
		}
		else
			i++;
	}
	if (symbol >= 0)
		symbol = symbol + write(1, &s[shift], i - shift);
	return (symbol);
}
