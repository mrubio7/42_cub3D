/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 08:48:59 by mrubio            #+#    #+#             */
/*   Updated: 2020/07/02 12:29:37 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	const char		*s2;
	int				x;

	s2 = s;
	x = 0;
	while (n-- > 0)
	{
		if (s2[x] == c)
			return ((unsigned char *)s2 + x);
		x++;
	}
	return (NULL);
}
