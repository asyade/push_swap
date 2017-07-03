/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:17:43 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/21 19:19:45 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dptr;
	unsigned char *sptr;

	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	if (dptr == sptr)
		return (dptr);
	if (dptr > sptr)
	{
		while (n--)
		{
			dptr[n] = sptr[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
