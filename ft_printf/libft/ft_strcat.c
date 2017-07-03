/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:21:39 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/12 20:18:21 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*dptr;

	dptr = dest;
	while (*dptr)
		dptr++;
	while (*src)
	{
		*dptr = *src;
		dptr++;
		src++;
	}
	*dptr = '\0';
	return (dest);
}
