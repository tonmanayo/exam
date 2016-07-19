/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:04:54 by tmack             #+#    #+#             */
/*   Updated: 2016/07/18 08:30:04 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		i;
	int		nbr;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	nbr= atoi(argv[1]);
	if (nbr == 1)
	{
		printf("1\n");
		return (0);
	}
	while (1)
	{
		i = 1;
		while (++i <= nbr)
		{
			if (nbr % i == 0)
			{
				printf("%d", i);
				nbr = nbr / i;
				break ;
			}
		}
		if (nbr == 1)
			break ;
		else
			printf("*");
	}
	printf("\n");
}
