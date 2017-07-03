/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:37:49 by acorbeau          #+#    #+#             */
/*   Updated: 2017/05/23 20:56:48 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **root, t_list *elem)
{
	if (*root != NULL)
	{
		elem->next = *root;
		*root = elem;
	}
	else
		*root = elem;
}
