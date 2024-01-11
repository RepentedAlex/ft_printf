/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:50:00 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/11 21:06:31 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int index)
{
	t_list	*new;

	new = malloc(1 * sizeof(t_list));
	if (!new)
		return (NULL);
	new->index = index;
	new->content = NULL;
	new->flag_minus = 0;
	new->flag_zero = 0;
	new->flag_dot = 0;
	new->flag_hashtag = 0;
	new->flag_plus = 0;
	new->flag_space = 0;
	new->next = NULL;
	return (new);
}
