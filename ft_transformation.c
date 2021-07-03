/*
* Created: 2020/07/31 18:55:03
*/

#include "libftprintf.h"

static int	ft_mult(long long int rslt_i, long long unsigned int rslt_u, int i)
{
	int	result;

	result = 1;
	if (rslt_u != 0)
	{
		while (i)
		{
			result = result * 10;
			i--;
		}
	}
	else if (rslt_i != 0)
	{
		while (i)
		{
			result = result * 10;
			i--;
		}
	}
	return (result);
}

void		ft_trans(long long int m, long long unsigned int u, int a, int len)
{
	int						ii;
	unsigned int			uu;
	long long int			flag_i;
	long long unsigned int	flag_u;
	int						count;

	flag_i = 1;
	flag_u = 1;
	if (len > 0)
		count = len - 1;
	else
		count = len;
	flag_i = ft_mult(flag_i, 0, count);
	flag_u = ft_mult(0, flag_u, count);
	while (len--)
	{
		ii = m / flag_i + 48;
		uu = u / flag_u + 48;
		count = (a == 'i') ? write(1, &ii, 1) : write(1, &uu, 1);
		u = u - (u / flag_u) * flag_u;
		m = m - (m / flag_i) * flag_i;
		flag_i = flag_i / 10;
		flag_u = flag_u / 10;
	}
}
