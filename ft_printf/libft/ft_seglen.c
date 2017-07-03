/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seglen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:24:51 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/14 18:27:10 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_seglen(char const *str, char c)
{
	size_t len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}
