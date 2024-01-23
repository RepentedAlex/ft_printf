/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:20:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/23 13:36:07 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr_fd(char *s, int fd, int n)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && i < n)
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	char	*string = "Kang-In Lee";
	int		fd = 1;

	ft_putstr_fd(string, fd);
}
*/
