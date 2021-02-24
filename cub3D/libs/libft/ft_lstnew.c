/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:24:12 by mrubio            #+#    #+#             */
/*   Updated: 2020/07/27 20:13:48 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if ((new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new = malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}
