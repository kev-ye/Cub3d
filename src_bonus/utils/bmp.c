/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:40:36 by kaye              #+#    #+#             */
/*   Updated: 2021/01/21 22:11:43 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void load_bar(long long current, long long max)
{
    long long bar_len;
    long long i;

    bar_len = 30;
    i = -1;
    ft_putstr(S_CLRLINE);
    while (++i < ((double)current / max) * bar_len)
        ft_putchar('|');
    while (i++ < bar_len)
        ft_putchar(' ');
    ft_putchar(' ');
    ft_putnbr_fd(((double)current / max) * 100, 1);
    ft_putchar('%');
    ft_putchar(' ');
}

static void     bmp_file_header(t_win *win, int fd)
{
    int size;
    
    write(fd, "BM", 2);
    size = win->img->bpp * win->img->width * win->img->height + 54 * 8;
    printf("Loading "S_CYAN"%s"S_NONE" ...\n", "save.bmp");
    write(fd, &size, 4);
    size = 0;
    write(fd, &size, 2);
    write(fd, &size, 2);
    size = 54;
    write(fd, &size, 4);
}

static void     bmp_infomation(t_win *win, int fd)
{
    int size;

    size = 40;
    write(fd, &size, 4);
    write(fd, &win->img->width, 4);
    write(fd, &win->img->height, 4);
    size = 1;
    write(fd, &size, 2);
    write(fd, &win->img->bpp, 2);
    size = 0;
    write(fd, &size, 4);
    write(fd, &size, 4);
    write(fd, &size, 4);
    write(fd, &size, 4);
    write(fd, &size, 4);
    write(fd, &size, 4);
}

static void bmp_data(t_win *win, int fd)
{
    char *ptr;
    int x;
    int y;

    y = win->img->height;
    while (y--)
    {
        x = -1;
        while (++x < win->img->width)
        {
            ptr = win->img->addr + (y * win->img->line_len + x * (win->img->bpp / 8));
            write(fd, &(*(int *)ptr), 4);
        }
        load_bar(win->img->height - y, win->img->height);
    }
}

void    make_bmp(t_win *win)
{
    int fd;

    win->save = 1;
    ray_casting(win);
    if ((fd = open("./save.bmp", O_WRONLY | O_CREAT)) == -1)
        msg_error(win, "Malloc in mode --save\n");
    bmp_file_header(win, fd);
    load_bar(0, win->img->height);
    bmp_infomation(win, fd);
    bmp_data(win, fd);
    close(fd);
    free_win(win);
    printf("-> "S_CYAN"DONE !\n"S_NONE);
    exit(0);
}