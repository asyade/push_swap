/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:24:23 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 12:49:55 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s || (ret = ft_memalloc(sizeof(char) * (len + 1))) == NULL)
		return ((char *)NULL);
	s += start;
	i = 0;
	while (i < len)
	{
		ret[i] = *s++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
