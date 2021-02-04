/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:51:42 by kaye              #+#    #+#             */
/*   Updated: 2021/02/02 09:49:21 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int check_map(char **map, int len_y_max)
{
    int check_x;
    int check_y;
    int resu_x;
    int resu_y;

    check_y = 0;
    resu_x = 0;
    resu_y = 0;
    while (check_y < len_y_max)
    {
        check_x = 0;
        while (check_x >= 0 && map[check_y][check_x])
        {
            if (map[check_y][check_x] == '0' || map[check_y][check_x] == '2' || map[check_y][check_x] == '3' || map[check_y][check_x] == '4') // add monster
            {
                resu_x = check_map_x(map, check_y, check_x);
                resu_y = check_map_y(map, check_y, check_x, len_y_max);
            }
            if ((map[check_y][check_x] == '0' || map[check_y][check_x] == '2' || map[check_y][check_x] == '3'|| map[check_y][check_x] == '4') && (!resu_x || !resu_y)) // add monster
                return (0);
            ++check_x;
        }
        ++check_y;
    }
    return (1);
}