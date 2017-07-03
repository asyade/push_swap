/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:09:45 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/21 19:20:59 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dptr;
	char	*sptr;

	dptr = (char *)dest;
	sptr = (char *)src;
	if (dest == src)
		return (dest);
	while (n--)
		*dptr++ = *sptr++;
	return (dest);
}
