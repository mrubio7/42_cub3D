/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:05:05 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/27 13:12:09 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdlib.h>
#include <unistd.h>

char *freemem(char *memf, char *pas)
{
	if (memf)
		free(memf);
	return (pas);
}

char 

