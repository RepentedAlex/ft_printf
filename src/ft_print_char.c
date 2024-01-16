/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:53:56 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/16 14:44:16 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../Libft/libft.h"

static void	ft_left_cs(t_print *tab, int a)
{
	int	i;

	if (tab->wdt > 1)
	{
		i = 0;
		tab->tl += write(1, &a, 1);
		i++;
		while (i < tab->wdt)
		{
			tab->tl += write(1, " ", 1);
			i++;
		}
	}
}

static void	ft_right_cs(t_print *tab, int a)
{
	int	i;

	if (tab->wdt > 1)
	{
		i = 0;
		while ((i + 1) < tab->wdt)
		{
			tab->tl += write(1, " ", 1);
			i++;
		}
		tab->tl += write(1, &a, 1);
	}
}

/*
void	ft_update_tab(t_print *tab, int a)
{
	
}
*/

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
//	ft_update_tab(tab, 1);
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, a);
	else if (tab->wdt && tab->dash)
		ft_left_cs(tab, a);
	else
		ft_putchar_fd(a, 1);
	return ;
}
