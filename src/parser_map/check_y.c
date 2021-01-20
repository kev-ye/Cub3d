/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:51:14 by kaye              #+#    #+#             */
/*   Updated: 2021/01/20 21:21:03 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_map_y2(char **map, int y, int x, int len_y_max,int get_wall)
{
    while (y >= 0 && map[y][x])
    {
        if (map[y][x] == '1')
        {
            get_wall++;
            break;
        }
        if (map[y][x] != '0' && map[y][x] != '2')
            return (0);
        --y;
    }
    return (get_wall);
}

int check_map_y(char **map, int y, int x, int len_y_max)
{
    int tmp_y;
    int get_wall;

    tmp_y = y;
    get_wall = 0;
    while (y < len_y_max && map[y][x])
    {
        if (map[y][x] == '1')
        {
            get_wall++;
            break;
        }
        if (map[y][x] != '0' && map[y][x] != '2')
            return (0);
        ++y;
    }
    y = tmp_y;
    get_wall = check_map_y2(map, y, x, len_y_max, get_wall);
    if (get_wall == 2)
        return (1);
    return (0);    
}