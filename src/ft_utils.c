
#include "../include/ft_printf.h"
#include "../Libft/libft.h"

int	ft_print_num(int n)
{
	int		len;
	char	*nb;

	len = 0;
	nb = ft_itoa(n);
	len = ft_print_string(nb);
	free(nb);
	return (len);
}