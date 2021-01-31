/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:20:32 by kaye              #+#    #+#             */
/*   Updated: 2021/01/31 20:57:23 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move_w(t_win *win)
{
    if (win->desc_info->map[(int)win->camera->pos_y]
                    [(int)(win->camera->pos_x + win->camera->dir_x
                    * win->camera->speed)] == '0')
        win->camera->pos_x += win->camera->dir_x * win->camera->speed;
    if (win->desc_info->map[(int)(win->camera->pos_y + win->camera->dir_y
                    * win->camera->speed)][(int)win->camera->pos_x] == '0')
        win->camera->pos_y += win->camera->dir_y * win->camera->speed;
}

void    move_s(t_win *win)
{
    if (win->desc_info->map[(int)win->camera->pos_y]
                    [(int)(win->camera->pos_x - win->camera->dir_x
                    * win->camera->speed)] == '0')
        win->camera->pos_x -= win->camera->dir_x * win->camera->speed;
    if (win->desc_info->map[(int)(win->camera->pos_y - win->camera->dir_y
                    * win->camera->speed)][(int)win->camera->pos_x] == '0')
        win->camera->pos_y -= win->camera->dir_y * win->camera->speed;
}

void    move_a(t_win *win)
{
    if (win->desc_info->map[(int)win->camera->pos_y]
                    [(int)(win->camera->pos_x - win->camera->plane_x
                    * win->camera->speed)] == '0')
        win->camera->pos_x -= win->camera->plane_x * win->camera->speed;
    if (win->desc_info->map[(int)(win->camera->pos_y - win->camera->plane_y
                    * win->camera->speed)][(int)win->camera->pos_x] == '0')
        win->camera->pos_y -= win->camera->plane_y * win->camera->speed;
}

void    move_d(t_win *win)
{
    if (win->desc_info->map[(int)win->camera->pos_y]
                    [(int)(win->camera->pos_x + win->camera->plane_x
                    * win->camera->speed)] == '0')
        win->camera->pos_x += win->camera->plane_x * win->camera->speed;
    if (win->desc_info->map[(int)(win->camera->pos_y + win->camera->plane_y
                    * win->camera->speed)][(int)win->camera->pos_x] == '0')
        win->camera->pos_y += win->camera->plane_y * win->camera->speed;
}