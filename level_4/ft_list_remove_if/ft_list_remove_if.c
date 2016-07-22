/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 10:05:06 by exam              #+#    #+#             */
/*   Updated: 2016/07/22 07:37:59 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*previous;

	temp = *begin_list;
	previous = 0;
	while (temp != 0)
	{
		if (cmp(temp->data, data_ref) == 0)
		{
			if (previous == 0)
				*begin_list = temp->next;
			else
				previous->next = temp->next;
		}
		previous = temp;
		temp = temp->next;
	}
}
