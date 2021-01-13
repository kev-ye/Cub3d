/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_place.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:48:16 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 20:53:36 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **get_player_place(char **map, int *p_x, int *p_y)
{
    int x;
    int y;

    y = 0;
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
            {
                *p_x = x;
                *p_y = y;
                map[y][x] = '0';
            }
            ++x;
        }
        ++y;
    }
    return (map);
}