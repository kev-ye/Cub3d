/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 21:43:00 by kaye              #+#    #+#             */
/*   Updated: 2020/12/26 19:56:20 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// int main()
// {
//     void    *mlx;
//     void    *mlx_win;
//     t_img  img;
//     int x = 400;
//     int y = 300;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 800, 600, "Cub3d");
//     img.img = mlx_new_image(mlx, 800, 600);
//     img.addr = mlx_get_img_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//     while (x < 800)
//     {
//         y = 300;
//         while (y < 600)
//         {
//             my_mlx_pixel_put(&img, x, y, RED);
//             ++y;
//         }
//         ++x;
//     }
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0 ,0);
//     mlx_loop(mlx);

//     return (0);
// }

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
    if (!(new_win->mlx_ptr = mlx_init()))
        return (ERROR);
    new_win->win_ptr = mlx_new_window(new_win->mlx_ptr, 640, 480, "Cub3d");
    return (new_win);
}

int main()
{
    t_win *win;

    if (!(win = init_mlx_win()))
        exit(0);
    mlx_hook(win->win_ptr, 2, 1L << 0, event_key_press, win);
    mlx_hook(win->win_ptr, 3, 1L << 1, event_key_release, win);
    mlx_hook(win->win_ptr, 17, 1L << 17, event_destroy_win, win);
    mlx_loop(win->mlx_ptr);
}