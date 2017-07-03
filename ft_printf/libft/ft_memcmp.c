/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:10:28 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/17 16:50:21 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *sa, const void *sb, size_t n)
{
	unsigned char	*ptra;
	unsigned char	*ptrb;
	size_t			i;

	i = 0;
	ptra = (unsigned char *)sa;
	ptrb = (unsigned char *)sb;
	while (i < n)
	{
		if (ptra[i] != ptrb[i])
			return (ptra[i] - ptrb[i]);
		i++;
	}
	return (0);
}
