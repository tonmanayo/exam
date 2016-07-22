/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 08:09:58 by tmack             #+#    #+#             */
/*   Updated: 2016/07/20 07:58:48 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		count_words(char *str)
{
	int		count;
	int		check;

	count = 0;
	while (*str)
	{
		check = 0;
		while (*str == ' ' || *str == '\t')
			str++;
		while (*str && *str != ' ' && *str != '\t')
		{
			str++;
			check = 1;
		}
		if (check)
			count++;
	}
	return (count);
}

int		word_len(char *str)
{
	int		len;

	len = 0;
	while (*str && *str != ' ' && *str != '\t')
	{
		len++;
		str++;
	}
	return (len);
}

void	fill_word(char *str, char **tab_str)
{
	int		i;

	i = 0;
	while (*str && *str != ' ' && *str != '\t')
	{
		(*tab_str)[i] = *str;
		str++;
		i++;
	}
	(*tab_str)[i] = '\0';
}

void	skip_space_tab(char **str)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
}

void	skip_word(char **str)
{
	while (**str && **str != ' ' && **str != '\t')
		(*str)++;
}

char	**ft_split(char *str)
{
	char	**tab;
	int		len;
	int		i;

	i = 0;
	len = count_words(str);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	tab[len] = NULL;
	skip_space_tab(&str);
	while (*str)
	{
		tab[i] = (char *)malloc(sizeof(char) * (word_len(str) + 1));
		fill_word(str, &tab[i]);
		skip_word(&str);
		skip_space_tab(&str);
		i++;
	}
	return (tab);
}

int main()
{
	char **str;
	char *line;
	int i;

	i = 0;
	line = "hello world";
	str = ft_split(line);
	while (str[i])
	{
		printf("%s\n", str[i++]);
	}
}
