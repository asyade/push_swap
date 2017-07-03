/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:23:20 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/17 15:36:12 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*sptr;
	char	*dptr;

	dptr = dest;
	sptr = (char *)src;
	while ((*dptr++ = *sptr++))
	{
	}
	return (dest);
}
