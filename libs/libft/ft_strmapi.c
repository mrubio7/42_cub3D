/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:24:09 by mrubio            #+#    #+#             */
/*   Updated: 2020/07/30 00:04:22 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int a, char b))
{
	int		x;
	int		size;
	char	*str;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	x = 0;
	if ((str = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	while (x < size)
	{
		str[x] = f(x, s[x]);
		x++;
	}
	str[x] = '\0';
	return (str);
}
