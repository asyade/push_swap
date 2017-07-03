/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:11:34 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/13 16:11:13 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*dptr;
	int		slen;
	int		dlen;
	int		i;

	slen = ft_strlen(src);
	i = size;
	dptr = dest;
	while (i-- && *dptr != '\0')
		dptr++;
	dlen = dptr - dest;
	i = size - dlen;
	if (i == 0)
		return (dlen + slen);
	while (*src)
	{
		if (i != 1)
		{
			*dptr++ = *src;
			i--;
		}
		src++;
	}
	*dptr = '\0';
	return (dlen + slen);
}
