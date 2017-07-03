/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:27:52 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 13:03:04 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	char			*sptr;
	char			*rptr;
	unsigned int	i;

	if (!f || !s || (ret = ft_strnew(ft_strlen(s))) == NULL)
		return ((char *)NULL);
	rptr = ret;
	sptr = (char *)s;
	i = 0;
	while (*sptr)
	{
		*rptr = f(i, *sptr);
		rptr++;
		sptr++;
		i++;
	}
	return (ret);
}
