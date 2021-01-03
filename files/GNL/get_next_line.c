/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:05:05 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/02 22:02:43 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_freemem(void *mem, void *ret)
{
	if (mem)
		free(mem);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int x;
	int z;
	char *str;

	x = 0;
	z = 0;
	while (s1[x])
		x++;
	str = malloc(x + 2);
	x = 0;
	while (s1[x])
		str[z++] = s1[x++];
	str[z++] = s2[0];
	str[z] = '\0';
	return (str);
}

int		ft_get_next_line(int fd, char **line)
{
	int bytes;
	char *buff;
	char *temp;

	if (!(buff = (char *)malloc(sizeof(char)* 2)) || !(*line = (char *)malloc(sizeof(char)* 1)))
		return (-1);
	(*line)[0] = '\0';
	while ((bytes = read(fd, buff, 1)) > 0)
	{
		buff[bytes] = '\0';
		if (buff[0] == '\n' || buff[0] == '\0')
			break;
		temp = ft_strjoin(*line, buff);
		*line = ft_freemem(*line, temp);
	}
	buff = ft_freemem(buff, NULL);
	return (bytes);
}
