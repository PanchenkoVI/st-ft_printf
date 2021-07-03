/*
* Created: 2020/07/31 18:55:03
*/

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flags {
	int		width;
	char	arg;
	int		fminus;
	int		zero;
	int		len;
	int		parser;
	int		precision;
	int		precsn_set;
}				t_type;

int				ft_printf(const char *format, ...);
int				ft_check(va_list list, const char *str, int symbol);
int				ft_fstruct(va_list list, t_type *flag, char *s, int i);
int				ft_cycle(va_list list, const char *str, int symbol);
void			ft_flag_d_i(va_list list, t_type *flag, long long int *d_i);
void			ft_flag_s(va_list list, t_type *flag, char **s);
void			ft_flag_cpxu(va_list list, t_type *flag, \
						long long unsigned int *cpxu);
void			ft_replacement(t_type *flag, long long unsigned u, \
						long long int d);
int				ft_fchar(char *s, int len, char c);
void			ft_width_pres(t_type *flag, long long unsigned u, \
						long long int m);
int				ft_spaces(int len, int *sing);
int				ft_type_calloc(t_type *flag, long long int *d, int count);
int				ft_print_isc(t_type *flag, char *s, long long int m);
void			ft_trans(long long int m, \
						long long unsigned int u, int a, int len);
int				ft_print_cxpu(t_type *flag, long long unsigned int m);

#endif
