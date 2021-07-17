#include "../ft_printf.h"

t_printf	struct_init(void)
{
	t_printf	t_fl;

	t_fl.flags = '\0';
	t_fl.width = 0;
	t_fl.precision = -1;
	t_fl.type = '\0';
	t_fl.status = 0;
	return (t_fl);
}
