/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:10:08 by mrubio            #+#    #+#             */
/*   Updated: 2020/07/27 20:18:42 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *str, int c)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	while ((str[x] != c) && (x > 0))
	{
		x--;
		if (str[x] == c)
			return ((char *)str + x);
	}
	if (!c && str[x] == '\0')
		return ((char *)str + x);
	return (NULL);
}
