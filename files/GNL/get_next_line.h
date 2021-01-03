/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:03:10 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/02 22:03:18 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_freemem(void *mem, void *ret);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

#endif
