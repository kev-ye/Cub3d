/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:11:06 by kaye              #+#    #+#             */
/*   Updated: 2020/12/27 23:18:49 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h> // to delete
#include "libft.h"

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

// CAMERA STRUCT
typedef struct      s_camera
{
    double pos_x;
    double pos_y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
    double cam_height;
    double speed;
}                   t_camera;

// RAY STRUCT
typedef struct      s_cam_ray
{
    int pix;
    int camera_x;
    int ray_dir_x;
    int ray_dir_y;
    int map_x;
    int map_y;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
    double delta_dist_y;
    double perp_wall_dist;
    int step_x;
    int step_y;
    int hit;
    int side;
    int line_height;
    int draw_start;
    int draw_end;
    double *z_buffer;
}                   t_cam_ray;

// DRAW IMAGE STRUCT
typedef struct      s_img 
{
    void *img_ptr;
    char *addr;
    int  bpp;
    int  line_len;
    int  endian;
    int  width;
    int  height;
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

// LINE STRUCT
typedef struct      s_line
{
    int line_x;
    int line_y;
    int y0;
    int y1;
}                   t_line;

// MAP STRUCT
typedef struct      s_map
{
    char **map;
    char *map_name;
    int map_width;
    int map_height;
}                   t_map;

// WINDOW STRUCT
typedef struct      s_win
{
    void        *mlx_ptr;
    void        *win_ptr;
    int         width;
    int         height;
    t_key       *key_code;
    t_img       *img;
    t_camera    *camera;
    t_map       *map;
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

// ENGINE FUNCION
    //Engine -> img
void    pixel_put(t_img *img, int x, int y, int color);
t_img   *new_image(t_win *win, int size_x, int size_y);
void    vertical_line(t_line *line, t_win *win, int color);
    // Engine -> ray_casting
void    init_raycating_value_calc(t_camera *cam, t_cam_ray *ray, t_win *win);
void    step_calc_init_side_dist(t_camera *cam, t_cam_ray *ray);
void    wall_hit(t_cam_ray *ray, t_win *win);
void    perpwalldist_and_heightline(t_camera *cam ,t_cam_ray *ray, t_win *win);
    // Engine ->camera move
void    move_w(t_win *win);
void    move_s(t_win *win);

// TEST FUNCTION
    //Engine -> draw
void    draw_something(t_win *win, t_img *img, int color);
    // Engine -> draw -> move
int    test_draw_move(t_win *win, t_img *img, int color);

#endif