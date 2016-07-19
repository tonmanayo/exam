/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 09:06:09 by tmack             #+#    #+#             */
/*   Updated: 2016/07/19 16:30:20 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int		ft_abs(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int				ft_len(long int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int nbr)
{
	int			len;
	int			absnbr;
	int			sign;
	char		*c;
	long int	temp;

	temp = nbr;
	sign = (nbr < 0) ? -1 : 1;
	len = ft_len(nbr);
	absnbr = ft_abs(nbr);
	c = (char *)malloc(sizeof(char) * len + 1);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(temp % 10);
		temp = ft_abs(temp / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
