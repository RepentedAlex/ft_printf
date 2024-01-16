/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:08:52 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/15 14:44:49 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../Libft/libft.h"

int	ft_eval_format(t_print *tab, char *format, int pos)
{
	while (format[pos] >= '0' && format[pos] <= '9' && tab->wdt == 0)
	{
		//GERER FIELD WIDTH
		tab->wdt = ft_atoi(&format[pos]);
	}
	while (ft_strchr("cspdiuxX%", format[pos]))
	{
		if (format[pos] == '#')
		{
			tab->alt = 1;
			pos++;
		}
		if (format[pos] == '0')
		{
			tab->zero = 1;
			pos++;
		}
		if (format[pos] == '.')
		{
			tab->pnt = 1;
			tab->prc = ft_atoi(&format[pos + 1]);
			pos++;
		}
		if (format[pos] == '+')
		{
			tab->sign = 1;
			pos++;
		}
		if (format[pos] == '-')
		{
			tab->dash = 1;
			pos++;
		}
		if (format[pos] == '%')
		{
			tab->perc = 1;
			pos++;
		}
	}
	if (tab->zero && tab->dash)
		tab->zero = 0;
	if (tab->sp && tab->sign)
		tab->sp = 0;
	return (pos);
	if (format[pos] == 'c')
		ft_print_char(tab);
	if (format[pos] == 's')
		ft_print_string(tab);
	if (format[pos] == 'p')
		ft_print_pointer(tab);
	if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_num(tab);
	if (format[pos] == 'u')
		ft_print_unsigned_num(tab);
	if (format[pos] == 'x')
		ft_print_hex_min(tab);
	if (format[pos] == 'X')
		ft_print_hex_maj(tab);
	if (format[pos] == '%')
		ft_print_perc(tab);
}

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->alt = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	tab->wdt = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_eval_format(tab, (char *)format, i + 1);
		else
			ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	free(tab);
	return (ret);
}

int	main(void)
{
	int c = 75;
	ft_printf("TEst:%4c\n", c);
}
