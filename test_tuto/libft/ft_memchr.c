/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:25:04 by ymoukhli          #+#    #+#             */
/*   Updated: 2018/10/12 17:12:56 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	size_t				i;

	i = 0;
	s1 = s;
	while (0 < n)
	{
		if (s1[i] == (unsigned char)c)
			return ((char *)s1 + i);
		i++;
		n--;
	}
	return (NULL);
}
