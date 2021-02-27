/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:37:07 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/08 19:57:37 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_index(double *dis, int *ord, int size)
{
	int i;
	int j;

	i = 0;
	j = size;
	while (i <= size)
		ord[i++] = 0;
	i = 0;
	while (i <= size)
	{
		dis[i] < dis[j] ? ord[i]++ : ord[i];
		if (j == 0 && (i += 1) <= size)
			j = size + 1;
		j--;
	}
	while (j <= size)
	{
		if (ord[j] == ord[j + 1])
		{
			ord[j]++;
			j = 0;
		}
		else
			j++;
	}
}
