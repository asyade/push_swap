/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:24:17 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 19:27:48 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	char	*ptr;

	if (!str)
		return (0);
	ptr = (char *)str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}
