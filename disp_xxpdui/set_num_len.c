#include "../ft_printf.h"

static int	numlen_base(unsigned long num, unsigned long base)
{
	int	len;

	len = 0;
	while (num >= base)
	{
		num = num / base;
		len++;
	}
	if (num < base)
		len++;
	return (len);
}

void	set_num_len(t_printf *t_fl, unsigned long num, int *len)
{
	if (t_fl->type == 'X' || t_fl->type == 'x')
		*len = numlen_base(num, 16);
	else if (t_fl->type == 'p')
		*len = numlen_base(num, 16) + 2;
	else
		*len = numlen_base(num, 10);
	if (t_fl->status == -1)
		(*len)++;
}
