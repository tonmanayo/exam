/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prac.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 07:16:46 by tmack             #+#    #+#             */
/*   Updated: 2016/08/22 07:28:19 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_abs(int nbr)
{
	return((nbr < 0) ? -nbr : nbr);
}

int		ft_len(int nbr, int base, int *store)
{
	int		i;
	int		sign;

	i = 0;
	sign = (nbr < 0) ? -1 : 1;
	while (nbr)
	{
		store[i] = ft_abs(nbr % base);
		nbr = nbr / base;
		i++;
	}
	if (base == 10 && sign == -1)
	{
		store[i] = '-';
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	static int base_digit[16] = {'0' , '1', '2', '3', '4', '5', '6', '7',
	   	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int		c[32];
	char	*new_line;
	int		i;
	int		j;

	if (base < 2 || base > 16 || value == 0)
		return ("0");
	i = 0;
	j = ft_len(value, base, c);
	new_line = malloc(j + 1);
	new_line[j] = '\0';
	while(j--)
	{
		if (c[i] == '-')
			new_line[j] = c[i];
		else
			new_line[j] = base_digit[c[i]];
		i++;	
	}
	return (new_line);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	int		i = atoi(argv[1]);
	int		j = atoi(argv[2]);
	printf("%s\n", ft_itoa_base(i , j));
}
