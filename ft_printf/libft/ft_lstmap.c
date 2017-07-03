/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:38:29 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 13:12:08 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_last;

	if (!lst || !f)
		return ((t_list *)NULL);
	ret_last = f(lst);
	ret = ret_last;
	if (ret == NULL)
		return ((t_list *)NULL);
	while (lst->next)
	{
		lst = lst->next;
		ret_last->next = f(lst);
		if (ret_last->next == NULL)
			return (NULL);
		ret_last = ret_last->next;
	}
	ret_last->next = NULL;
	return (ret);
}
