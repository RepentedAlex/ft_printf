/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:19:08 by apetitco          #+#    #+#             */
/*   Updated: 2023/11/14 15:34:02 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s);
	while (s[i] != (unsigned char)c)
	{
		if (i == 0 && s[i] != c)
			return ((char *)0);
		i--;
	}
	return ((char *)&s[i]);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*test = "Marco Verratti";
	int		charset = 'a';

	char	*found = ft_strrchr(test, charset);
	if (found != NULL)
		printf("%s\n", found);
	else
		printf("Character not found.\n");
}
*/
