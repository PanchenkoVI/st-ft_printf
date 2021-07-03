/*
* Created: 2020/07/31 18:55:03
*/

#include "libftprintf.h"

int			ft_printf(const char *format, ...)
{
	va_list		list;
	int			symbol;

	va_start(list, format);
	symbol = 0;
	symbol = ft_check(list, format, symbol);
	va_end(list);
	if (symbol < 0)
		return (-1);
	va_start(list, format);
	symbol = 0;
	symbol = ft_cycle(list, format, symbol);
	va_end(list);
	return (symbol);
}
