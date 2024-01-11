/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:06:02 by apetitco          #+#    #+#             */
/*   Updated: 2023/11/14 15:27:08 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == 0)
			return ((char *)0);
		i++;
	}
	return ((char *)&s[i]);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*test = "Kang-In Lee";
	int		charset = 'N';

	char	*found = ft_strchr(test, charset);
	if (found != NULL)
		printf("%s\n", found);
	else
		printf("Character not found.\n");
}
*/
