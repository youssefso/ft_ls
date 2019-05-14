/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:58:56 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/04 19:50:10 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_only_one(char *flag)
{
	char *s;
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	s = ft_strnew(ft_strlen(flag));
	while (flag[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (flag[i] == flag[j])
				break ;
			j++;
		}
		if (j == i)
			s[k++] = flag[i];
		i++;
	}
	s[k] = '\0';
	free(flag);
	return (s);
}
