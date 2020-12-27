/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:05:05 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/27 13:49:26 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_find_n(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == '\n')
			return (x);
		x++;
	}
	return (-1);
}

static int		ft_movestr(char **str, int x, char **line, char *newstr)
{
	char	*temp;

	(*str)[x] = '\0';
	*line = ft_strdup(*str);
	free(newstr);
	if (ft_strlen(*str + x + 1) > 0)
	{
		temp = ft_strdup(*str + x + 1);
		free(*str);
		*str = temp;
	}
	else
		ft_bzero(*str, ft_strlen(*str));
	return (1);
}

static int		ft_find_eof(char **str, char **line)
{
	int		find;

	if (*str && (find = ft_find_n(*str)) > -1)
		return (ft_movestr(str, find, line, NULL));
	else
	{
		*line = *str;
		*str = NULL;
	}
	return (0);
}

static void		ft_addstr(char **str, char *newstr)
{
	char	*temp;

	temp = ft_strjoin(*str, newstr);
	free(*str);
	*str = temp;
}

int				ft_get_next_line(int fd, char **line)
{
	static char		*str[256];
	char			*newstr;
	int				x;
	int				r;

	if (fd < 0 || fd > 256 || !line || BUFFER_SIZE <= 0
	|| !(newstr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((r = read(fd, newstr, BUFFER_SIZE)) > 0)
	{
		newstr[r] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(newstr);
		else
			ft_addstr(&str[fd], newstr);
		if ((x = ft_find_n(str[fd])) > -1)
			return (ft_movestr(&str[fd], x, line, newstr));
	}
	free(newstr);
	if (r < 0)
		return (-1);
	if (r == 0 && str[fd])
		return (ft_find_eof(&str[fd], line));
	*line = ft_strdup("");
	return (0);
}
/*
int     main(void)
{
    int fd;
    char **lines;
    int a;
    int i;

    i = 0;
    lines = malloc(999);
    fd = open("/Users/macbookpro/Desktop/42/42_get_next_line/prueba.txt", O_RDONLY);
    while ((a = get_next_line(fd, lines)) > 0)
    {
        printf("Linea %i ---- %s\n",i, lines[fd-3]);
        i++;
    }
    printf("Linea %i ---- %s\n",i, lines[fd-3]);
}
*/
