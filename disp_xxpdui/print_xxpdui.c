#include "../ft_printf.h"

void	print_xxpdui(va_list v_list, t_printf *t_fl, int *result)
{
	int				len;
	unsigned long	num;

	num_set(t_fl, v_list, &num);
	set_num_len(t_fl, num, &len);
	correct_xxpdui(t_fl, &num, len);
	start_print_xxpdui(t_fl, &num, result);
}
