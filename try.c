/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 14:12:39 by tmack             #+#    #+#             */
/*   Updated: 2016/07/12 16:44:14 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int ft_abs(int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int	ft_len(int nbr)
{
	int absnbr;
	int len;

	absnbr = ft_abs(nbr);
	len = (nbr <= 0) ? 1 : 0;
	while (absnbr > 0)
	{
		absnbr = absnbr / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nbr, int base)
{
	int len;
	char *c;
	int sign;
	int absnbr;

	absnbr = ft_abs(nbr);
	sign = (nbr < 0) ? -1 : 1;
	len = ft_len(nbr);
	c = (char *)malloc(sizeof(char) * len);
	len--;
		if (absnbr / base)
			ft_itoa(absnbr / base, base);
	while (len >= 0)
	{
		absnbr = absnbr % base;
		if (absnbr >= 0 && absnbr <= 9)
			c[len] = absnbr + '0';
		else if (absnbr >= 10 && absnbr <= (base - 1))
			c[len] = absnbr + 87;
		len--;
	}
	if (sign  == -1)
		c[0] = '-';
	return (c);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	int i;
	char *c;

	if (argc != 3)
		return (0);
	c = ft_itoa(atoi(argv[1]), atoi(argv[2]));
	printf("%s\n", c);
}
