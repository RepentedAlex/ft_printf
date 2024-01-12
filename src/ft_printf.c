/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:08:52 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/11 22:35:49 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../Libft/libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	t_list	**head;
	va_list	args;

	if (!str || *str == 0)
		return (-1);
	va_start(args, str);
	head = NULL;
	ft_parse(str, head, args);
	print_len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len++; //CHANGER POUR AJOUTER NOMBRE DE CARACTERES PRINTES
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			print_len++;
		}
		i++;
	}
	va_end(args);
	return (print_len);
}

int	main(void)
{
	int num = 12;
	char	*str = "Kanz";
	ft_printf("Voici la variable a afficher %+-0 #d et ceci est le texte qui finit %s\n", num, str);
}
