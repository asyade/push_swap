/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:39:53 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 15:46:22 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lptr;
	void	*dptr;

	if ((lptr = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		lptr->content_size = 0;
		lptr->content = NULL;
	}
	else
	{
		if ((dptr = malloc(content_size)) == NULL)
		{
			free(lptr);
			return (NULL);
		}
		lptr->content_size = content_size;
		lptr->content = ft_memcpy(dptr, content, content_size);
	}
	lptr->next = NULL;
	return (lptr);
}
