#include "../ft_printf.h"

void	print_str(va_list va_list, t_printf *t_fl, int *result)
{
	char	*s;
	int		len;

	s = va_arg (va_list, char *);
	len = ft_modif_strlen(s);
	correct_str(s, t_fl, len);
	start_print_str(s, t_fl, result);
}
