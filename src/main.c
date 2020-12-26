/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 21:43:00 by kaye              #+#    #+#             */
/*   Updated: 2020/12/27 00:18:19 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void shut_down(t_win *win)
{
    mlx_destroy_window(win->mlx_ptr, win->win_ptr);
    exit(0);
}

static t_win *init_mlx_win(void)
{
    t_win *new_win;

    if (!(new_win = malloc(sizeof(t_win))))
        exit(1);
    ft_bzero(new_win, sizeof(t_win));
    if (!(new_win->mlx_ptr = mlx_init()))
        return (ERROR);
    new_win->win_ptr = mlx_new_window(new_win->mlx_ptr, 800, 600, "Cub3d");
    return (new_win);
}

int init_key(t_win *win)
{
    if (!(win->key_code = malloc(sizeof(t_key))))
        return (ERROR);
    ft_bzero(win->key_code, sizeof(t_key));
    win->key_code->key_w = 0;
    win->key_code->key_s = 0;
    win->key_code->key_a = 0;
    win->key_code->key_d = 0;
    win->key_code->key_left = 0;
    win->key_code->key_right = 0;
    return (SUCCESS);    
}

int init_camera(t_win *win)
{
    if (!(win->camera = malloc(sizeof(t_camera))))
        return (ERROR);
    ft_bzero(win->camera, sizeof(t_camera));
    win->camera->pos_x = 400;
    win->camera->pos_y = 300;
    return (SUCCESS);
}

int    test_draw_move(t_win *win, t_img *img, int color)
{
    if (win->key_code->key_w == 1)
    {
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
        if (!(img = new_image(win, 10, 10)))
            exit(0);
        win->camera->pos_y -= 10;
        draw_something(win, img, RED);
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
    }
    else if (win->key_code->key_s == 1)
    {
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
        if (!(img = new_image(win, 10, 10)))
            exit(0);
        win->camera->pos_y += 10;
        draw_something(win, img, RED);
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
    }
    else if (win->key_code->key_a == 1)
    {
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
        if (!(img = new_image(win, 10, 10)))
            exit(0);
        win->camera->pos_x -= 10;
        draw_something(win, img, RED);
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
    }
    else if (win->key_code->key_d == 1)
    {
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
        if (!(img = new_image(win, 10, 10)))
            exit(0);
        win->camera->pos_x += 10;
        draw_something(win, img, RED);
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
    }
    return (SUCCESS);
}

int main()
{
    t_win *win;
    t_img *img;

    if (!(win = init_mlx_win()) ||
        !(init_key(win)) ||
        !(init_camera(win)))
        exit(0);
    if (!(img = new_image(win, 10, 10)))
        exit(0);
    draw_something(win, img, RED);
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
    // test_draw_move(win, img, RED);
    mlx_hook(win->win_ptr, 2, 1L << 0, event_key_press, win);
    mlx_hook(win->win_ptr, 3, 1L << 1, event_key_release, win);
    mlx_hook(win->win_ptr, 17, 1L << 17, event_destroy_win, win);
    mlx_loop_hook(win->mlx_ptr, test_draw_move, win);
    mlx_loop(win->mlx_ptr);
    return (0);
}