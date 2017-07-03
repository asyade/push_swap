/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:40:46 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/17 21:26:12 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && n-- >= len)
	{
		if (ft_strncmp(to_find, &(str[i]), len) == 0)
		{
			return ((char *)&(str[i]));
		}
		i++;
	}
	return (NULL);
}
