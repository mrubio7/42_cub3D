/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:47:13 by mrubio            #+#    #+#             */
/*   Updated: 2020/07/27 19:47:14 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	int x;
	int z;

	x = 0;
	z = 0;
	while ((dest[x]) && (x < (int)size))
		x++;
	while ((src[z]) && (x + z + 1) < (int)size)
	{
		dest[x + z] = src[z];
		z++;
	}
	if (x < (int)size)
		dest[x + z] = '\0';
	return (x + ft_strlen(src));
}
