/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:38:02 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/17 12:38:05 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **root, void (*f)(void *, size_t))
{
	if ((*root)->next)
		ft_lstdel(&((*root)->next), f);
	ft_lstdelone(root, f);
}
