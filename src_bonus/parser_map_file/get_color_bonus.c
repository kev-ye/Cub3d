/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:01:34 by kaye              #+#    #+#             */
/*   Updated: 2021/01/31 21:17:33 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int get_color(char **s)
{
    int r;
    int g;
    int b;
    int color;

    r = ft_atoi(s[0]);
    g = ft_atoi(s[1]);
    b = ft_atoi(s[2]);
    if (r > 255 || g > 255 || b > 255)
        return (-1);
    color = create_rgb(r, g, b);
    return (color);
}

int check_and_get_color(char *s)
{
    char **color;
    int count;
    int c;

    count = 0;
    if (ft_charinstr(s, ',') != 2)
        return (-1);
    if (!(color = ft_split(s, ',')))
        return (-1);
    while (color[count] != NULL)
        ++count;
    if (count != 3)
    {
        free_split(color);
        return (-1);
    }
    count = 0;
    while (color[0][count])
    {
        if (color[0][count] && !ft_isdigit(color[0][count]))
        {
            free_split(color);
            return (-1);
        }
        ++count;
    }
    count = 0;
    while (color[1][count])
    {
        if (color[1][count] && !ft_isdigit(color[1][count]))
        {
            free_split(color);
            return (-1);
        }
        ++count;
    }
    count = 0;
    while (color[2][count])
    {
        if (color[2][count] && !ft_isdigit(color[2][count]))
        {
            free_split(color);
            return (-1);
        }
        ++count;
    }
    c = get_color(color);
    free_split(color);
    if (c == -1)
        return (-1);
    return (c);
}