/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_place_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:48:16 by kaye              #+#    #+#             */
/*   Updated: 2021/01/31 21:17:19 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char **get_player_place(char **map, int *p_x, int *p_y, t_desc_info *desc_info, t_desc desc)
{
    int x;
    int y;

    y = 0;
    while (y < desc_info->map_y)
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
            {
                desc.player++;
                *p_x = x;
                *p_y = y;
                desc_info->player_dir = (int)map[y][x];
                map[y][x] = '0';
            }
            ++x;
        }
        ++y;
    }
    if (desc.player > 1 || desc.player < 1)
            return (NULL);
    return (map);
}