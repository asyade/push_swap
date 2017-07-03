/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 20:00:56 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/18 22:20:34 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				sign;
	unsigned char	size;
	char			*ret;

	sign = (n >= 0) ? 1 : -1;
	nb = n * sign;
	size = (sign == -1) ? 2 : 1;
	while (nb /= 10)
		size++;
	if ((ret = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	ret[size] = '\0';
	nb = n * sign;
	while (size--)
	{
		ret[size] = nb % 10 + '0';
		nb /= 10;
	}
	ret[0] = (sign == -1) ? '-' : ret[0];
	return (ret);
}
