/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:37:28 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/14 16:04:49 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s1_2;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(s1_2 = (char *)malloc(i + 1)))
		return (NULL);
	s1_2 = ft_strcpy(s1_2, s1);
	s1_2 = ft_strcat(s1_2, s2);
	return (s1_2);
}
