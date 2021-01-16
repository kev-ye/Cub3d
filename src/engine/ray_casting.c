/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:05:42 by kaye              #+#    #+#             */
/*   Updated: 2021/01/16 13:52:35 by kaye             ###   ########.fr       */
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
    mapping(ray, win);
}

int ray_casting(t_win *win)
{
    t_cam_ray *ray;

    if (!(ray = malloc(sizeof(t_cam_ray))))
        return (ERROR);
    ft_bzero(ray, sizeof(t_cam_ray));
    while (ray->pix < win->width)
    {
        ray_casting_regroup(win, ray);
        ++ray->pix;
    }
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img_ptr, 0, 0);
    free(ray);
    return (SUCCESS);
}