/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:25:35 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/12 19:19:03 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *a, const char *b, size_t n)
{
	char	*ptra;
	char	*ptrb;

	ptra = (char *)a;
	ptrb = (char *)b;
	if (!ptra && !ptrb)
		return (0);
	while (*ptra && *ptrb && *ptra == *ptrb && n--)
	{
		ptra++;
		ptrb++;
	}
	return (n == 0) ? 0 : ((unsigned char)*ptra - (unsigned char)*ptrb);
}
