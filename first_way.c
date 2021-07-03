/*
* Created: 2020/07/31 18:55:03
*/

#include "libftprintf.h"

static int		ft_analysis(va_list list, char *str, int *i, int symbol)
{
	t_type		flag;

	*i = ft_fstruct(list, &flag, str, *i);
	if (flag.arg == 0)
		return (-1);
	return (symbol);
}

int				ft_check(va_list list, const char *str, int symbol)
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
			symbol = symbol + i - shift;
			symbol = ft_analysis(list, s, &i, symbol);
			shift = i;
		}
		else
			i++;
	}
	if (symbol >= 0)
		symbol = symbol + i - shift;
	return (symbol);
}
