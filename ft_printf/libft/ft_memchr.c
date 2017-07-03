/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:58:38 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/12 21:24:14 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;

	sptr = (void *)s;
	while (n--)
	{
		if (*sptr == (unsigned char)c)
			return ((void *)sptr);
		sptr++;
	}
	return ((void *)0);
}
