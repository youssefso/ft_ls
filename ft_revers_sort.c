/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revers_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 06:32:46 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/05 07:44:23 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_revers_sort(t_param *t)
{
	t_param *start;
	t_param *tmp;
	int i = 0;
	int j = 0;
	int k = 0;

	start = t;
	tmp = t;
	while (start != NULL)
	{
		start = start->next;
		i++;
	}
	j = i / 2;
	while (i > j)
	{
		k = 1;
		start = t;
		while (k++ < i)
			start = start->next;
		ft_swap_param(start, tmp);
		i--;
		tmp = tmp->next;
	}
}
