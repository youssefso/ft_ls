/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sltocu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:25:33 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/04 17:46:21 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_strlookup(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}
char	*ft_sltocu(const char *s, char c)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			k = i;
		i++;
	}
	if (k != 0 && s[k] != '\0')
		return ((char *)(s + k));
	else
		return ((char *)s);
}
