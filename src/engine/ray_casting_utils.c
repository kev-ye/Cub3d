/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:05:34 by kaye              #+#    #+#             */
/*   Updated: 2020/12/27 23:10:45 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"

void    init_raycating_value_calc(t_camera *cam, t_cam_ray *ray, t_win *win)
{
    ray->camera_x = 2 * ray->pix / (double)win->width - 1;
    ray->ray_dir_x = cam->dir_x + cam->plane_x * ray->camera_x;
    ray->ray_dir_y = cam->dir_y + cam->plane_y * ray->camera_x;
    ray->map_x = (int)cam->pos_x;
    ray->map_y = (int)cam->pos_y;
    ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
    ray->hit = 0;
}

void    step_calc_init_side_dist(t_camera *cam, t_cam_ray *ray)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (cam->pos_x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - cam->pos_x) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (cam->pos_y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - cam->pos_y) * ray->delta_dist_y;
    }
}

void    wall_hit(t_cam_ray *ray, t_win *win)
{
    while (ray->hit == 0)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_y;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y  += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (win->map->map[ray->map_x][ray->map_y] > '0')
            ray->hit = 1;
    }
}

void    perpwalldist_and_heightline(t_camera *cam ,t_cam_ray *ray, t_win *win)
{
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->map_x - cam->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
        ray->perp_wall_dist = (ray->map_y - cam->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
    ray->line_height = (int)(win->height / ray->perp_wall_dist);
    ray->draw_start = -ray->line_height / 2 + win->height / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + win->height / 2;
    if (ray->draw_end >= win->height)
        ray->draw_end = win->height - 1;
}