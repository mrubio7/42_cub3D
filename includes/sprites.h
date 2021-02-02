/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:13:55 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/02 19:44:28 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
#define	SPRITES_H

typedef struct	s_spos
{
	double		x;
	double		y;
	int			texture;
}				t_spos;

#define numSprites 5

t_spos sprites[0] = {20.5, 11.5, 10};
t_spos sprites[1] = {18.5,4.5, 10};
t_spos sprites[2] = {10.0,4.5, 10};
t_spos sprites[3] = {10.0,12.5,10};
t_spos sprites[4] = {3.5, 6.5, 10};

#endif