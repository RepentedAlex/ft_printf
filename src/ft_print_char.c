/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:53:56 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/15 14:57:52 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../Libft/libft.h"

void	ft_left_cs(t_print *tab, int a)
{
	int	i;

	if (tab->wdt >= a)
	{
		i = 0;
		while (i < tab->wdt)
		{
			tab->tl += write(1, &a, 1);
			i++;
		}
	}
}

void	ft_right_cs(t_print *tab, int a)
{
	int	i;

	if (tab->wdt >= a)
	{
		i = 0;
		while (i < tab->wdt)
		{
			tab->tl += write(1, " ", 1);
			i++;
		}
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
	{
		ft_right_cs(tab, a);
		tab->tl += write(1, &a, 1);
	}
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, 0);
	return ;
}
