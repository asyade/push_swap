/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:24:56 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/17 15:37:06 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*sptr;
	char	*dptr;

	sptr = (char *)src;
	dptr = dest;
	while (*dptr)
		dptr++;
	while (n--)
	{
		if (!(*dptr++ = *sptr++))
			return (dest);
	}
	*dptr = '\0';
	return (dest);
}
