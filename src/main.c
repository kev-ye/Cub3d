/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 21:43:00 by kaye              #+#    #+#             */
/*   Updated: 2021/01/17 17:38:39 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_win *init_mlx_win(char *path)
{
    t_win *new_win;

    if (!(new_win = malloc(sizeof(t_win))))
        return (NULL);
    ft_bzero(new_win, sizeof(t_win));
    if (!(new_win->desc_info = check_file(path)))
        return (NULL);
    if (!(new_win->mlx_ptr = mlx_init()))
        return (NULL);
    new_win->width = new_win->desc_info->r_x;
    new_win->height = new_win->desc_info->r_y;
    if (!(new_win->win_ptr = mlx_new_window(new_win->mlx_ptr,
                                new_win->width, new_win->height, "Cub3d")))
        return (NULL);
    if (!(new_win->img = new_image(new_win, new_win->width, new_win->height)))
        return (NULL);
    return (new_win);
}

int main(int ac, char **av)
{
    t_win *win;
    (void)ac;

    if (!(win = init_mlx_win(av[1])) || !(init_key(win)) ||
          !(init_camera(win)) || !(init_tex(win)))
        msg_error("Error : Malloc/mlx error");
    mlx_hook(win->win_ptr, 2, 1L << 0, event_key_press, win);
    mlx_hook(win->win_ptr, 3, 1L << 1, event_key_release, win);
    mlx_hook(win->win_ptr, RED_CROSS, 1L << 2, event_destroy_win, win);
    mlx_loop_hook(win->mlx_ptr, event_loop, win);
    mlx_loop(win->mlx_ptr);
    return (0);
}
