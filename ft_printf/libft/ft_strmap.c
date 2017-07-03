/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:12:11 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 12:54:09 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	char	*sptr;
	char	*rptr;

	if (!s || (ret = ft_strnew(ft_strlen(s))) == NULL)
		return ((char *)NULL);
	rptr = ret;
	sptr = (char *)s;
	while (*sptr)
	{
		*rptr = f(*sptr);
		rptr++;
		sptr++;
	}
	*rptr = '\0';
	return (ret);
}
