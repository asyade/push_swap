/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:39:19 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/21 12:32:10 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;

	if (!s1 && !s2)
		return ((char *)NULL);
	else if (s1 && !s2)
		return ((char *)ft_strdup(s1));
	else if (s2 && !s1)
		return ((char *)ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = ft_memalloc(len * sizeof(char) + 1)) == 0)
		return ((char *)NULL);
	ft_strcat(str, s1);
	return (ft_strcat(str, s2));
}
