/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:09:42 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 12:48:25 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	unsigned int	start;
	size_t			end;
	size_t			i;

	if (!str)
		return ((char *)NULL);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i] == '\0')
		return (ft_strdup(""));
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	start = (unsigned int)i;
	while (str[i])
		i++;
	i--;
	while (i > 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i--;
	end = i + 1;
	return (ft_strsub(str, start, end - start));
}
