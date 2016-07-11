/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 09:03:56 by exam              #+#    #+#             */
/*   Updated: 2016/07/06 09:59:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *c)
{
	int	sign;
	int	number;
	int	i;

	i = 0;
	sign = 1;
	number = 0;
	if (c[i] == ' ' || c[i] == '\t')
		i++;
	if (c[i] == '-')
		sign = -1;
	if (c[i] == '+' || c[i] == '-')
		i++;
	while (c[i] && c[i] >= '0' && c[i] <= '9')
	{
		number = (number * 10) + c[i] - '0';
		i++;
	}
	return (number * sign);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int		ft_is_prime(int nbr)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i <= nbr)
	{
		if (nbr % i == 0)
			count++;
		i++;
	}
	return (count);
}

int		main(int argc, char **argv)
{
	int	i;
	int	count;
	int	total;

	total = 0;
	if (argc != 2)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (0);
	}
	i = ft_atoi(argv[1]);
	if (i < 0)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (0);
	}
	count = -1;
	while (++count <= i)
		if (ft_is_prime(count) == 2)
			total = total + count;
	ft_putnbr(total);
	ft_putchar('\n');
}
