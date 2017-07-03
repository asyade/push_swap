/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:23:44 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/12 13:46:55 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *str)
{
	char	*ret;

	if ((ret = ft_strnew(ft_strlen(str) + 1)) == NULL)
		return ((char *)0);
	ft_strcpy(ret, str);
	return (ret);
}
