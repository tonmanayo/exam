/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 07:11:01 by tmack             #+#    #+#             */
/*   Updated: 2016/07/11 07:35:44 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_abs(int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int	ft_len(int nbr)
{
	int		len;
	int		absnbr;

	absnbr = ft_abs(nbr);
	len = (nbr <= 0) ? 1 : 0;
	while (absnbr > 0)
	{
		absnbr = absnbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*c;
	int		absnbr;
	int		len;
	int		sign;

	absnbr = ft_abs(nbr);
	len = ft_len(nbr);
	c = (char *)malloc(sizeof(char) * len);
	sign = (nbr < 0) ? 1 : 0;
	len--;
	while (len >= 0)
	{
		c[len] = '0' + absnbr % 10;
		absnbr = absnbr / 10;
		len--;
	}

	if (sign == 1)
		c[0] = '-';
	return (c);
}
