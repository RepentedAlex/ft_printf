/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:12 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/15 14:37:34 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../Libft/libft.h"
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

typedef	struct	s_print
{
		va_list	args;
		int		wdt;
		int		prc;
		int		alt;
		int		zero;
		int		pnt;
		int		dash;
		int		tl;
		int		sign;
		int		is_zero;
		int		perc;
		int		sp;
}				t_print;

int		ft_eval_format(t_print *tab, char *format, int pos);
t_print	*ft_initialise_tab(t_print *tab);
void	ft_left_cs(t_print *tab, int a);
void	ft_print_char(t_print *tab);
void	ft_print_hex_min(t_print *tab);
void	ft_print_hex_maj(t_print *tab);
void	ft_print_num(t_print *tab);
void	ft_print_perc(t_print *tab);
void	ft_print_pointer(t_print *tab);
void	ft_print_string(t_print *tab);
void	ft_print_unsigned_num(t_print *tab);
int		ft_printf(const char *format, ...);
void	ft_right_cs(t_print *tab, int a);
void	ft_update_tab(t_print *tab, int a);

#endif
