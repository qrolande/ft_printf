#include "../ft_printf.h"

int	ft_modif_strlen(char *s)
{
	int			i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}
