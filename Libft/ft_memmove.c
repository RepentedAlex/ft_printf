/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:29:18 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/08 15:42:26 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dup_src;
	unsigned char	*dup_dest;

	if (!src && !dest)
		return (dest);
	dup_src = (unsigned char *)src;
	dup_dest = (unsigned char *)dest;
	i = 0;
	if (dest > src)
	{
		while (n != 0)
		{
			dup_dest[n - 1] = dup_src[n - 1];
			n--;
		}
	}
	while (i < n)
	{
		dup_dest[i] = dup_src[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	ft_memmove(sResult + 1, sResult, 2);
	printf("%s\n", sResult2);
}
*/
