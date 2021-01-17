/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:11:06 by kaye              #+#    #+#             */
/*   Updated: 2021/01/17 16:50:56 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <libc.h> // to delete
#include <fcntl.h>
#include "libft.h"

/*
** TRUE/FALSE
*/
#define SUCCESS 1
#define ERROR 0

/*
** KEY CODE
*/
#define KEY_CODE_ESC 53
#define KEY_CODE_W 13
#define KEY_CODE_S 1
#define KEY_CODE_A 0
#define KEY_CODE_D 2
#define KEY_CODE_LEFT 123
#define KEY_CODE_RIGHT 124
#define RED_CROSS 17

/*
** COLOR CODE
*/
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define YELLOW 0xFFFF00
#define WHITE 0xFFFFFF

/*
** STRUCT - CAMERA/PLAYER
*/
typedef struct      s_camera
{
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
    double  cam_height;
    double  speed;
    double  rot_speed;
}                   t_camera;

/*
** STURCT - RAYCASTING
*/
typedef struct      s_cam_ray
{
    int     pix;
    double  camera_x;
    double  ray_dir_x;
    double  ray_dir_y;
    int     map_x;
    int     map_y;
    double  side_dist_x;
    double  side_dist_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  perp_wall_dist;
    int     step_x;
    int     step_y;
    int     hit;
    int     side;
    int     line_height;
    int     draw_start;
    int     draw_end;
}                   t_cam_ray;

/*
** STRUCT - IMAGE
*/
typedef struct      s_img 
{
    void    *img_ptr;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     width;
    int     height;
}                   t_img;

/*
** STRUCT - EVENT KEY
*/
typedef struct      s_key
{
    int     key_w;
    int     key_s;
    int     key_a;
    int     key_d;
    int     key_left;
    int     key_right;
}                   t_key;

/*
** STRUCT - DRAW LINE
*/
typedef struct      s_line
{
    int     line_x;
    int     line_y;
    int     draw_start;
    int     draw_end;
    int     tex_x;
    int     tex_y;
}                   t_line;

/*
** STRUCT - DESCRITION UTILS
*/
typedef struct      s_desc
{
    int map;
    int player;
    int r;
    int no;
    int so;
    int we;
    int ea;
    int s;
    int f;
    int c;
}                   t_desc;

/*
** STRUCT - DESCRIPTION INFORMATION
*/
typedef struct       s_desc_info
{
    int r_x;
    int r_y;
    char *path_no;
    char *path_so;
    char *path_we;
    char *path_ea;
    char *path_s;
    int color_f;
    int color_c;
    int player_x;
    int player_y;
    int player_dir;
    char **map;
    int map_width;
    int map_height;
}                   t_desc_info;

/*
** STRUCT - REGROUP
*/
typedef struct      s_win
{
    void        *mlx_ptr;
    void        *win_ptr;
    int         width;
    int         height;
    t_key       *key_code;
    t_img       *img;
    t_camera    *camera;
    t_img       **texture;
    t_desc_info *desc_info;
}                   t_win;

/*
** QUIT
*/
void shut_down(t_win *win);

/*
** EVENT
*/
int     event_destroy_win(t_win *win);
int     event_key_press(int keycode, t_win *win);
int     event_key_release(int keycode, t_win *win);
int     event_key(t_win *win);
int     event_loop(t_win *win);

/*
** IMAGE
*/
t_img   *new_image(t_win *win, int size_x, int size_y);
void    pixel_put_color(t_img *img, int x, int y, int color);
void    vertical_line_color(t_line *line, t_win *win, int color);
void    vertical_line_tex(t_line *line, t_win *win, t_img *texture, t_cam_ray *ray);
void    pixel_put_tex(t_line *line, t_img *texture, t_win *win, t_cam_ray *ray);

/*
** TEXTURE
*/
int     set_texture(t_win *win, const char *path, int index);
int     load_texture(t_win *win);

/*
** RAYCASTING
*/
void    init_raycating_value_calc(t_camera *cam, t_cam_ray *ray, t_win *win);
void    step_calc_init_side_dist(t_camera *cam, t_cam_ray *ray);
void    wall_hit(t_cam_ray *ray, t_win *win);
void    perpwalldist_and_heightline(t_camera *cam ,t_cam_ray *ray, t_win *win);
int     ray_casting(t_win *win);

/*
** PLAYER MOUVEMENT
*/
void    move_w(t_win *win);
void    move_s(t_win *win);
void    move_a(t_win *win);
void    move_d(t_win *win);

/*
** CAMERA TURN
*/
void    turn_left(t_win *win);
void    turn_right(t_win *win);

/*
** MAPPING
*/
void   draw_side(t_cam_ray *ray, t_win *win, t_line *line, double wall_x);
void   draw_ceiling_floor(t_win *win, t_line *line, t_cam_ray *ray);
void   mapping(t_cam_ray *ray, t_win *win);

/*
** PARSER - INIT
*/
t_desc          init_desc();
t_desc_info     *init_desc_info();

/*
** PARSER - GET INFORMATION
*/
int             get_resoltion(char *line, t_desc_info *desc_info);
int             check_and_get_color(char *s);
int             get_floor_color(char *line, t_desc_info *desc_info);
int             get_ceiling_color(char *line, t_desc_info *desc_info);
int             get_path(char *line, t_desc_info *desc_info);

/*
** PARSER - CHECK FILE
*/
int             check_file_name(const char *path);
int             check_file_line(char *line, t_desc *desc,
                                                    t_desc_info *desc_info);
int             check_map_ready(t_desc desc);
int             check_no_map(char *line, t_desc *desc);
int             check_map_norm(char *line, t_desc *desc);
int             check_path(t_desc_info *desc_info);
t_desc_info     *check_file(const char *path);

/*
** PARSER - MAP
*/
char            **get_map(const char *path, int *len_max_y);
char            **get_player_place(char **map, int *p_x, int *p_y,
                                                    t_desc_info *desc_info);
int             check_map_x(char **map, int y, int x);
int             check_map_y(char **map, int y, int x);
int             check_map(char **map, int px, int py);

/*
** INIT/UTILS
*/
void    msg_error(char *msg);
int		create_rgb(int r, int g, int b);
void    free_split(char **s);
void    free_desc_info(t_desc_info *desc_info);
void    shut_down(t_win *win);
int     init_camera(t_win *win);
int     init_key(t_win *win);
int     init_tex(t_win *win);

#endif