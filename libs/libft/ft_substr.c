/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:35:16 by mrubio            #+#    #+#             */
/*   Updated: 2020/07/30 19:57:14 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*res;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((res = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	while (x < (int)len)
	{
		res[x] = s[start + x];
		x++;
	}
	res[x] = '\0';
	return (res);
}
