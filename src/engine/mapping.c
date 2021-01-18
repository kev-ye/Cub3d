/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:21:27 by kaye              #+#    #+#             */
/*   Updated: 2021/01/18 12:05:04 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_side(
    t_cam_ray *ray,
    t_win *win,
    t_line *line,
    double wall_x)
{
    int  tex_x;
    t_img *img;

    img = win->texture[0];
    if (ray->side == 1)
        img = win->texture[1];
    if (ray->side == 2)
        img = win->texture[2];
    if (ray->side == 3)
        img = win->texture[3];
    tex_x = (int)(wall_x * (double)img->width);
    if ((ray->side == 0 || ray->side == 1)&& ray->ray_dir_x > 0)
        tex_x = img->width - tex_x - 1;
    if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y < 0)
        tex_x = img->width - tex_x - 1;
    line->draw_start = ray->draw_start;
    line->draw_end = ray->draw_end;
    line->tex_x = tex_x;
    vertical_line_tex(line, win, img, ray);
}

void    draw_ceiling_floor(
    t_win *win,
    t_line *line,
    t_cam_ray *ray)
{
    line->draw_start = 0;
	line->draw_end = ray->draw_start;
	vertical_line_color(line, win, win->desc_info->color_c);
	line->draw_start = ray->draw_end;
	line->draw_end = win->height;
	vertical_line_color(line, win, win->desc_info->color_f);
}

void    mapping(
    t_cam_ray *ray,
    t_win *win)
{
    t_line *line;
    double wall_x;

    if (!(line = malloc(sizeof(t_line))))
        return ;
    ft_bzero(line, sizeof(t_line));
    line->line_x = ray->pix;
    if (ray->side == 0 || ray->side == 1)
        wall_x = win->camera->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    else
        wall_x = win->camera->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
    wall_x -= floor(wall_x);
    if (win->desc_info->map[ray->map_y][ray->map_x] == '1')
        draw_side(ray, win, line, wall_x);
    draw_ceiling_floor(win, line, ray);
    free(line);
}

int     set_texture(
    t_win *win,
    const char *path,
    int index)
{
    if (!(win->texture[index]->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
                                    (char *)path, &win->texture[index]->width,
                                    &win->texture[index]->height)))
        return (ERROR);
    win->texture[index]->addr = mlx_get_data_addr(win->texture[index]->img_ptr,
                    &win->texture[index]->bpp, &win->texture[index]->line_len,
                    &win->texture[index]->endian);
    return (SUCCESS);
}

int     load_texture(t_win *win)
{
    int tex_1;
    int tex_2;
    int tex_3;
    int tex_4;

    tex_1 = set_texture(win, win->desc_info->path_no, 0);
    tex_2 = set_texture(win, win->desc_info->path_so, 1);
    tex_3 = set_texture(win, win->desc_info->path_ea, 2);
    tex_4 = set_texture(win, win->desc_info->path_we, 3);
    if (!tex_1 || !tex_2 || !tex_3 || !tex_4)
        return (ERROR);
    return (SUCCESS);
}