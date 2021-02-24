/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:48:20 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/13 17:09:21 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const void *str1, const void *str2, unsigned int n)
{
	const char	*s1;
	const char	*s2;
	int			x;

	s1 = str1;
	s2 = str2;
	x = 0;
	while ((x < (int)n) && (s1[x] != '\0' || s2[x] != '\0'))
	{
		if (s1[x] != s2[x])
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	return (0);
}
