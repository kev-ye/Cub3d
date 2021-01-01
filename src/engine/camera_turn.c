/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:00:09 by kaye              #+#    #+#             */
/*   Updated: 2020/12/31 21:26:28 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    turn_left(t_win *win)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = win->camera->dir_x;
    old_plane_x = win->camera->plane_x;
    win->camera->dir_x = win->camera->dir_x 
        * cos(win->camera->rot_speed) - win->camera->dir_y
        * sin(win->camera->rot_speed);
    win->camera->dir_y = old_dir_x 
        * sin(win->camera->rot_speed) + win->camera->dir_y
        * cos(win->camera->rot_speed);
    win->camera->plane_x = win->camera->plane_x
        * cos(win->camera->rot_speed) - win->camera->plane_y
        * sin(win->camera->rot_speed);
    win->camera->plane_y = old_plane_x
        * sin(win->camera->rot_speed) + win->camera->plane_y
        * cos(win->camera->rot_speed);
}

void    turn_right(t_win *win)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = win->camera->dir_x;
    old_plane_x = win->camera->plane_x;
    win->camera->dir_x = win->camera->dir_x 
        * cos(-win->camera->rot_speed) - win->camera->dir_y
        * sin(-win->camera->rot_speed);
    win->camera->dir_y = old_dir_x 
        * sin(-win->camera->rot_speed) + win->camera->dir_y
        * cos(-win->camera->rot_speed);
    win->camera->plane_x = win->camera->plane_x
        * cos(-win->camera->rot_speed) - win->camera->plane_y
        * sin(-win->camera->rot_speed);
    win->camera->plane_y = old_plane_x
        * sin(-win->camera->rot_speed) + win->camera->plane_y
        * cos(-win->camera->rot_speed);
}