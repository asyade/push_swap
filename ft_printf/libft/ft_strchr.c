/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 19:03:10 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/13 13:33:24 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int tf)
{
	char	*sptr;
	int		i;
	char	c;

	i = 0;
	sptr = (char *)s;
	c = (char)tf;
	if (*sptr == c)
		return (sptr);
	while (sptr[i++])
	{
		if (sptr[i] == c)
			return (&sptr[i]);
	}
	return ((char *)NULL);
}
