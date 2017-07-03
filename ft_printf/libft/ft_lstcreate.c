/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 20:54:58 by acorbeau          #+#    #+#             */
/*   Updated: 2017/05/23 20:54:59 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstcreate(void *content, size_t content_size)
{
	t_list	*lptr;

	lptr = malloc(sizeof(t_list));
	lptr->content = content;
	lptr->next = NULL;
	lptr->content_size = content_size;
	return (lptr);
}
