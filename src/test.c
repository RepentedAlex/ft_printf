#include "../include/ft_printf.h"
#include "../Libft/libft.h"
#include <stdio.h>

int	main(void)
{
	int 	c = 75;
	char	*str = "Kang-In Lee";

	printf("printf original %%c ; Test:'%c'\n", c);
	ft_printf("ft_printf %%c ; Test:'%c'\n", c);
	printf("printf original %%4c ; Test:'%4c'\n", c);
	ft_printf("ft_printf %%4c ; Test:'%4c'\n", c);
	printf("printf original %%-4c Test:'%-4c'\n", c);
	ft_printf("ft_printf %%-4c ; Test:'%-4c'\n", c);

	printf("\n\n");

	printf("printf original %%s ; Test:'%s'\n", str);
	ft_printf("ft_printf %%s ; Test:'%s'\n", str);
	printf("printf original %%-s ; Test:'%-s'\n", str);
	ft_printf("ft_printf %%-s ; Test:'%-s'\n", str);
	printf("printf original %%40s ; Test:'%40s'\n", str);
	ft_printf("ft_printf %%40s ; Test:'%40s'\n", str);
	printf("printf original %%-40s Test:'%-40s'\n", str);
	ft_printf("ft_printf %%-40s ; Test:'%-40s'\n", str);
}
