/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:35:18 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 20:59:09 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		nbw;
	int		reading;
	char	*str;
	char	*word;

	nbw = ft_segcount(s, c);
	if (!s || !(ret = (char **)ft_memalloc(sizeof(char *) * (nbw + 1))))
		return ((char **)NULL);
	reading = 0;
	str = (char *)s - 1;
	while (nbw && ++str)
	{
		if (reading == 0 && *str != c && nbw-- && !(reading = 0))
		{
			if (!(word = (char *)ft_memalloc(2 + ft_seglen(str, c))))
				return ((char **)NULL);
			*ret++ = word;
			while (*str && *str != c)
				*word++ = *str++;
			*word = '\0';
		}
	}
	*ret = NULL;
	return (ret -= ft_segcount(s, c));
}
