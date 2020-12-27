/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:49:53 by kaye              #+#    #+#             */
/*   Updated: 2020/12/27 23:02:02 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move_w(t_win *win)
{
    if (win->map->map[(int)(win->camera->pos_x + win->camera->dir_x * win->camera->speed)][(int)win->camera->pos_y] == '0')
        win->camera->pos_x += win->camera->dir_x * win->camera->speed;
    if (win->map->map[(int)win->camera->pos_x][(int)(win->camera->pos_y + win->camera->dir_y * win->camera->speed)] == '0')
        win->camera->pos_y += win->camera->dir_y * win->camera->speed;
}

void    move_s(t_win *win)
{
    if (win->map->map[(int)(win->camera->pos_x - win->camera->dir_x * win->camera->speed)][(int)win->camera->pos_y] == '0')
        win->camera->pos_x -= win->camera->dir_x * win->camera->speed;
    if (win->map->map[(int)win->camera->pos_x][(int)(win->camera->pos_y - win->camera->dir_y * win->camera->speed)] == '0')
        win->camera->pos_y -= win->camera->dir_y * win->camera->speed;
}

// void    move_a(t_win *win)
// {
    
// }