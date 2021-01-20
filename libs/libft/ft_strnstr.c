/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:30:54 by mrubio            #+#    #+#             */
/*   Updated: 2020/07/09 17:52:03 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *lit, unsigned int n)
{
	int	x;
	int	z;

	if (lit[0] == '\0')
		return ((char *)big);
	x = 0;
	while (big[x] && x < (int)n)
	{
		z = 0;
		if (big[x] == lit[z])
		{
			while (x + z < (int)n && big[x + z] == lit[z])
			{
				z++;
				if (!lit[z])
					return ((char *)big + x);
			}
		}
		x++;
	}
	return (0);
}
