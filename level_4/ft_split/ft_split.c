/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 08:09:58 by tmack             #+#    #+#             */
/*   Updated: 2016/07/11 08:36:48 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		count_words(char *str)
{
	int		count;
	int		check;

	i = 0;
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
		(*str_tab)[i] = *str;
		str++;
		i++;
	}
	(*str_tab)[i] = '\0';
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
	len = count_word(str);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	tab[len] = NULL;
	skip_space_tab(&str);
	while (*str)
	{
		tab[i] = (char *)malloc(sizeof(char) * (len_word(str) + 1));
		fill_word_tab(str, &tab[i]);
		skip_word(&str);
		skip_space_tab(&str);
		i++;
	}
	return (tab);
}
