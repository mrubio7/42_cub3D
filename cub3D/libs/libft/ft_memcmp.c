/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:28:12 by mrubio            #+#    #+#             */
/*   Updated: 2020/07/02 12:08:10 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_memcmp(const void *str1, const void *str2, unsigned int n)
{
	const char	*s1;
	const char	*s2;
	int			x;

	s1 = str1;
	s2 = str2;
	x = 0;
	while (x < (int)n)
	{
		if (s1[x] != s2[x])
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	return (0);
}
