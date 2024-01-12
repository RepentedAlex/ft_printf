/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:39:58 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/11 22:39:39 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../Libft/libft.h"
#include <stdio.h>

void	ft_assign_content(t_list *node, char *str, va_list args)
{
	if (node->type == 1)
		node->content = va_arg(args, char);
	if (*str == 's')
		node->type = 2;
	if (*str == 'p')
		node->type = 3;
	if (*str == 'd')
		node->type = 4;
	if (*str == 'i')
		node->type = 5;
	if (*str == 'u')
		node->type = 6;
	if (*str == 'x')
		node->type = 7;
	if (*str == 'X')
		node->type = 8;
	if (*str == '%')
		node->type = 9;
	return ;
}

void	ft_parse_type(char *str, int *index, t_list *node)
{
	if (*str == 'c')
		node->type = 1;
	if (*str == 's')
		node->type = 2;
	if (*str == 'p')
		node->type = 3;
	if (*str == 'd')
		node->type = 4;
	if (*str == 'i')
		node->type = 5;
	if (*str == 'u')
		node->type = 6;
	if (*str == 'x')
		node->type = 7;
	if (*str == 'X')
		node->type = 8;
	if (*str == '%')
		node->type = 9;
	return ;
}


void	ft_check_flags(t_list *node)
{
	if (node->flag_minus && node->flag_zero)
		node->flag_zero = 0;
	if (node->flag_plus && node->flag_space)
		node->flag_space = 0;
	return ;
}

int	ft_get_precision(char *str)
{
	if (ft_isdigit(*(char *)str + 1) == 1)
		return ((*(str + 1)) - '0');
	return (0);
}

void	ft_parse_flags(char *str, int *index, t_list *node)
{
	int	in_flags;

	in_flags  = 1;
	while (str[*index] && in_flags == 1)
	{
		if (str[*index] == '-')
			node->flag_minus = 1;
		else if (str[*index] == '0')
			node->flag_zero = 1;
		else if (str[*index] == '.')
			{
				ft_get_precision(&str[*index]);
				node->flag_dot = 1;
			}
		else if (str[*index] == '#')
			node->flag_hashtag = 1;
		else if (str[*index] == '+')
			node->flag_plus = 1;
		else if (str[*index] == ' ')
			node->flag_space = 1;
		else
		{
			in_flags = 0;
			ft_check_flags(node);
			ft_parse_type(str, index, node);
			(*index)++;
			return ;
		}
		(*index)++;
	}
}

int	ft_conversion_specifier(char *str, t_list *node)
{
	int	i;

	i = 0;
	ft_parse_flags(str, &i, node);
	ft_parse_type(str, &i, node);
	return (i);
}

void	ft_parse(const char *str, t_list **lst, va_list args)
{
	int	i;
	t_list	*tmp;

	(void)lst;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = ft_lstnew(i);
			//AJOUTER CONTENT PUIS ADDBACK
			i += ft_conversion_specifier((char *)&str[i + 1], tmp);
			ft_assign_content(tmp, (char *)&str[i], args);
		}
		i++;
	}
	//CONTINUER JUSQUE FIN DE LA STRING
	//RETOUR SPECIAL SI ERREUR
	return ;
}
