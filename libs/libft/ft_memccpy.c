/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:33:38 by mrubio            #+#    #+#             */
/*   Updated: 2020/07/02 10:56:21 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	x;

	x = 0;
	while (x < n)
	{
		*(unsigned char *)(dest + x) = *(unsigned char *)(src + x);
		if (*(unsigned char *)(src + x) == (unsigned char)c)
			return (dest + x + 1);
		x++;
	}
	return (NULL);
}
