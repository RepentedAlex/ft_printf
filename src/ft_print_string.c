/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:25:49 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/16 15:12:43 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../Libft/libft.h"

static void	ft_left_cs(t_print *tab, char *str)
{
	int	i;
	int	len;

	len = (int)ft_strlen(str);
	tab->tl += ft_putstr_fd(str, 1);
	if (tab->wdt > len)
	{
		i = 0;
		while ((i + len) < tab->wdt)
		{
			tab->tl += write(1, " ", 1);
			i++;
		}
	}
}

static void	ft_right_cs(t_print *tab, char *str)
{
	int	i;
	int	len;

	len = (int)ft_strlen(str);
	if (tab->wdt > len)
	{
		i = 0;
		while ((i + len) < tab->wdt)
		{
			tab->tl += write(1, " ", 1);
			i++;
		}
	}
	tab->tl += ft_putstr_fd(str, 1);
}

/*
void	ft_update_tab(t_print *tab, int a)
{

}
*/

void	ft_print_string(t_print *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
//	ft_update_tab(tab, 1);
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, str);
	else if (tab->wdt && tab->dash)
		ft_left_cs(tab, str);
	else
		ft_putstr_fd(str, 1);
	return ;
}
