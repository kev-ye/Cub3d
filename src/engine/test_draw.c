/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:00:56 by kaye              #+#    #+#             */
/*   Updated: 2020/12/27 18:01:16 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    test_draw_move(t_win *win, t_img *img, int color)
{
    if (win->key_code->key_w == 1)
    {
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
        if (!(img = new_image(win, 10, 10)))
            exit(0);
        if (win->camera->pos_y > 0)
            win->camera->pos_y -= 10;
        draw_something(win, img, RED);
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
    }
    else if (win->key_code->key_s == 1)
    {
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
        if (!(img = new_image(win, 10, 10)))
            exit(0);
        if (win->camera->pos_y < 590)
            win->camera->pos_y += 10;
        draw_something(win, img, RED);
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
    }
    else if (win->key_code->key_a == 1)
    {
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
        if (!(img = new_image(win, 10, 10)))
            exit(0);
        if (win->camera->pos_x > 0)
            win->camera->pos_x -= 10;
        draw_something(win, img, RED);
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
    }
    else if (win->key_code->key_d == 1)
    {
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
        if (!(img = new_image(win, 10, 10)))
            exit(0);
        if (win->camera->pos_x < 790)
            win->camera->pos_x += 10;
        draw_something(win, img, RED);
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
    }
    return (SUCCESS);
}