/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 08:38:17 by tmack             #+#    #+#             */
/*   Updated: 2016/07/12 09:42:49 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
	}

int	len2(int nbr)
{
	int len1;
	int absnbr;

	absnbr = ft_abs(nbr);
	len1 = (nbr <= 0) ? 1 : 0;
	while (absnbr > 0)
	{
		absnbr = absnbr / 10;
		len1++;
	}
	return (len1);
}

char *ft_itoa(int nbr)
{
	int absnbr;
	int len;
	char *c;
	int sign;

	sign = (nbr < 0) ? 1 : 0;
	len = len2(nbr);
	absnbr = ft_abs(nbr);
	c = (char *)malloc(sizeof(char) * len);
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

int	ft_atoi(char *c)
{
	int nbr;
	int sign;
	int i;

	i = 0;
	nbr = 0;
	sign = 
}
#include <stdio.h>
int main()
{
	int i;
	char *c;
	i = 0;
	c = ft_itoa(i);
	printf("%s\n", c);
}
