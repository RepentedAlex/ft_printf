/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:32:19 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/08 15:19:03 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	failure(t_list *node, t_list *ret, void (*del)(void *))
{
	if (!node && ret != NULL)
	{
		ft_lstclear(&ret, *del);
		return (0);
	}
	if (!node)
		return (0);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*ret;

	node = NULL;
	ret = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (failure(node, ret, del) == 0)
			return (NULL);
		ft_lstadd_back(&ret, node);
		lst = lst->next;
	}
	return (ret);
}
