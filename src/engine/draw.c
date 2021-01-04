/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:21:27 by kaye              #+#    #+#             */
/*   Updated: 2021/01/03 17:21:52 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_side(t_cam_ray *ray, t_win *win, t_line *line, int color, double wall_x)
{
    int  tex_x;
    t_img *img;

    if (ray->side == 1)
        color = color / 2;
    tex_x = (int)(wall_x * (double)img->width);
    if (ray->side == 0 && ray->ray_dir_x > 0)
        tex_x = img->width - tex_x - 1;
    if (ray->side == 1 && ray->ray_dir_y < 0)
        tex_x = img->width - tex_x - 1;
    line->y0 = ray->draw_start;
    line->y1 = ray->draw_end;
    line->tex_x = tex_x;
    // vertical_line_tex(???);
}

void    draw_text(t_cam_ray *ray, t_win *win)
{
    t_img *img;
    t_line *line;
    int color;
    double wall_x;

    if (!(line = malloc(sizeof(t_line))))
    {
        ft_putstr("ERROR LINE");
        exit(0);
    }
    ft_bzero(line, sizeof(t_line));
    line->line_x = ray->pix;
    if (ray->side == 0)
        wall_x = win->camera->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    else
        wall_x = win->camera->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
    wall_x -= floor(wall_x);
    if (win->map->map[ray->map_y][ray->map_x] == '1')
    {
        //draw_side();
        color = BLUE;
    }
    if (ray->side == 1)
        color = color / 2;
    line->y0 = ray->draw_start;
    line->y1 = ray->draw_end;
    vertical_line_color(line, win, color);
    line->y0 = 0;
	line->y1 = ray->draw_start;
	vertical_line_color(line, win, RED);
	line->y0 = win->height;
	line->y1 = ray->draw_end;
	vertical_line_color(line, win, GREEN);
}

int     set_texture(t_win *win, const char *path, int index)
{
    if (!(win->texture[index]->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, (char *)path, &win->texture[index]->width, &win->texture[index]->height)))
        return (ERROR);
    win->texture[index]->addr = mlx_get_data_addr(win->texture[index]->img_ptr, &win->texture[index]->bpp, &win->texture[index]->line_len, &win->texture[index]->endian);
    return (SUCCESS);
}

int     load_texture(t_win *win)
{
    int i;
    i = set_texture(win, "./textures/east.xpm", 0);
    if (!i)
        return (ERROR);
    return (SUCCESS);
    
}