/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:32:53 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/17 14:10:13 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	if ((ft_strlen(str) == 0 && ft_strlen(to_find) == 0))
		return ((char *)str);
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = i;
			while (str[j] == to_find[j - i] || to_find[j - i] == '\0')
			{
				if (to_find[j - i] == '\0')
					return ((char *)&str[i]);
				j++;
			}
		}
		else if (str[i] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
