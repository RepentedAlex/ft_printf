/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:12 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/11 19:30:45 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

void	ft_parse(const char *str, t_list **lst, va_list args);

#endif
