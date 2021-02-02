/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:26:26 by kaye              #+#    #+#             */
/*   Updated: 2021/02/02 14:25:25 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    put_hud(t_win *win)
{
    mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 20, WHITE, "test");
}