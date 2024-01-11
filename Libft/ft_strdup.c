/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/08 15:51:11 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		length;

	length = (ft_strlen((char *)s) + 1);
	duplicate = (char *)ft_calloc(length, sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, s, length);
	duplicate[length - 1] = 0;
	return (duplicate);
}

/*
#include <stdio.h>

int	main(void)
{
	char	test[] = "lorem ipsum dolor sit amet";
	char	*duplicate;

	duplicate = ft_strdup(test);
	printf("%s\n", duplicate);
	free(duplicate);
	printf("%s\n", duplicate);
}
*/
