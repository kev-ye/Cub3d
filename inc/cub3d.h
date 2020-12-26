/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:11:06 by kaye              #+#    #+#             */
/*   Updated: 2020/12/26 19:47:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h> // to delete

// RETURN VALUE
#define SUCCESS 1
#define ERROR 0

// KEYBOARD CODE
#define KEY_CODE_ESC 53
#define KEY_CODE_W 13
#define KEY_CODE_S 1
#define KEY_CODE_A 0
#define KEY_CODE_D 2
#define KEY_CODE_LEFT 123
#define KEY_CODE_RIGHT 124

// COLOR CODE
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF

// ?
typedef struct      s_camera
{
    int pos_x;
    int pos_y;
    int dir_x;
    int dir_y;
    int plane_x;
    int plane_y;
    int height_camera;
}                   t_camera;

// DRAW IMAGE STRUCT
typedef struct      s_img 
{
    void *img;
    char *addr;
    int  bits_per_pixel;
    int  line_length;
    int  endian;
}                   t_img;

// KEYBOARD STRUCT
typedef struct      s_key
{
    int key_w;
    int key_s;
    int key_a;
    int key_d;
    int key_left;
    int key_right;
}                   t_key;

// WINDOW STRUCT
typedef struct      s_win
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_key       *key_code;
}                   t_win;

// COLOR FUNCTION
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// CLOSE FUNCTION
void shut_down(t_win *win);

// EVENT FUNCTION
    // Event -> window
int event_destroy_win(t_win *win);
    // Event -> keyboard
int event_key_press(int keycode, t_win *win);
int event_key_release(int keycode, t_win *win);

#endif