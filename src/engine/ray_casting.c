/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:05:42 by kaye              #+#    #+#             */
/*   Updated: 2020/12/27 23:23:11 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     ray_casting_regroup(t_win *win, t_cam_ray *ray)
{
    t_camera *cam;

    cam = win->camera;
    init_raycating_value_calc(cam, ray, win);
    step_calc_init_side_dist(cam, ray);
    wall_hit(ray, win);
    perpwalldist_and_heightline(cam, ray, win);
    ray->z_buffer[ray->pix] = ray->perp_wall_dist;
    ++ray->pix;
}

int ray_casting(t_win *win)
{
    t_cam_ray *ray;

    if (!(ray = malloc(sizeof(t_cam_ray))))
        return (ERROR);
    ft_bzero(ray, sizeof(t_cam_ray));
    if (!(ray->z_buffer = malloc(sizeof(double) * win->width)))
        return (ERROR);
    ft_bzero(ray->z_buffer, sizeof(double) * win->width);
    while (ray->pix < win->width)
        ray_casting_regroup(win, ray);
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img_ptr, 0, 0);
    free(ray->z_buffer);
    free(ray);
    return (SUCCESS);
}