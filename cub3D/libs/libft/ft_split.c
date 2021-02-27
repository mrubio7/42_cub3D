/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:52:14 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 20:11:35 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		numstring(char const *s1, char c)
{
	int	strgs;
	int	sw;

	strgs = 0;
	sw = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			sw = 0;
		else if (sw == 0)
		{
			sw = 1;
			strgs++;
		}
		s1++;
	}
	return (strgs);
}

static int		numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char		**ft_free(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char		**swapstr(char const *s, char **dst, char c, int strgs)
{
	int	x;
	int	z;
	int	i;

	x = 0;
	z = 0;
	while (s[x] != '\0' && z < strgs)
	{
		i = 0;
		while (s[x] == c)
			x++;
		dst[z] = (char *)malloc(sizeof(char) * numchar(s, c, x) + 1);
		if (dst[z] == NULL)
			return (ft_free((char const **)dst, z));
		while (s[x] != '\0' && s[x] != c)
			dst[z][i++] = s[x++];
		dst[z][i] = '\0';
		z++;
	}
	dst[z] = 0;
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	int		strgs;

	if (s == NULL)
		return (NULL);
	strgs = numstring(s, c);
	dst = (char **)malloc(sizeof(char *) * (strgs + 1));
	if (dst == NULL)
		return (NULL);
	return (swapstr(s, dst, c, strgs));
}
