/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:56:33 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/19 18:18:14 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	unsigned int	retval;
	int				sign;

	retval = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		sign = (*nptr++ == '+') ? 1 : -1;
	while (ft_isdigit(*nptr))
	{
		retval *= 10;
		retval += *nptr - '0';
		nptr++;
	}
	return ((int)(retval * sign));
}
