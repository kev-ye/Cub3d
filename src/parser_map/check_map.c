/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:51:42 by kaye              #+#    #+#             */
/*   Updated: 2021/01/18 19:43:59 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_map_1(char **map, int px, int py)
{
    int check_x;
    int check_y;
    int resu_x;
    int resu_y;

    check_y = py;
    resu_x = 0;
    resu_y = 0;
    while (check_y >= 0)
    {
        check_x = px;
        while (check_x >= 0)
        {
            if (map[check_y][check_x] == '0')
            {
                resu_x = check_map_x(map, check_y, check_x);
                resu_y = check_map_y(map, check_y, check_x);
            }
            if (map[check_y][check_x] == '0' && (!resu_x || !resu_y))
                return (0);
            --check_x;
        }
        --check_y;
    }
    return (1);
}

static int check_map_2(char **map, int px, int py)
{
    int check_x;
    int check_y;
    int resu_x;
    int resu_y;

    check_y = py;
    resu_x = 0;
    resu_y = 0;
    while (check_y >= 0)
    {
        check_x = px;
        while (map[check_y][check_x] != '\0')
        {
            if (map[check_y][check_x] == '0')
            {
                resu_x = check_map_x(map, check_y, check_x);
                resu_y = check_map_y(map, check_y, check_x);
            }
            if (map[check_y][check_x] == '0' && (!resu_x || !resu_y))
                return (0);
            ++check_x;
        }
        --check_y;
    }
    return (1);
}

static int check_map_3(char **map, int px, int py, int len_y_max)
{
    int check_x;
    int check_y;
    int resu_x;
    int resu_y;

    check_y = py;
    resu_x = 0;
    resu_y = 0;
    while (check_y < len_y_max)
    {
        check_x = px;
        while (check_x >= 0)
        {
            if (map[check_y][check_x] == '0')
            {
                resu_x = check_map_x(map, check_y, check_x);
                resu_y = check_map_y(map, check_y, check_x);
            }
            if (map[check_y][check_x] == '0' && (!resu_x || !resu_y))
                return (0);
            --check_x;
        }
        ++check_y;
    }
    return (1);
}

static int check_map_4(char **map, int px, int py, int len_y_max)
{
    int check_x;
    int check_y;
    int resu_x;
    int resu_y;

    check_y = py;
    resu_x = 0;
    resu_y = 0;
    while (check_y < len_y_max)
    {
        check_x = px;
        while (map[check_y][check_x] != '\0')
        {
            if (map[check_y][check_x] == '0')
            {
                resu_x = check_map_x(map, check_y, check_x);
                resu_y = check_map_y(map, check_y, check_x);
            }
            if (map[check_y][check_x] == '0' && (!resu_x || !resu_y))
                return (0);
            ++check_x;
        }
        ++check_y;
    }
    return (1);
}

int check_map(char **map, int px, int py, int len_y_max)
{
    if (px == -99 || py == -99)
        return (0);
    if (check_map_1(map, px, py) && check_map_2(map, px, py) && check_map_3(map, px, py, len_y_max) && check_map_4(map, px, py, len_y_max))
        return (1);
    return (0);
}