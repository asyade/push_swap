/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:38:19 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 13:11:16 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *root, void (*f)(t_list *e))
{
	if (!root || !f)
		return ;
	f(root);
	if (root->next)
		ft_lstiter(root->next, f);
}
