/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:02:39 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 18:02:57 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_floor_color(char *line, t_desc_info *desc_info)
{
    int count;
    char **s;

    count = 0;
    if (!(s = ft_split(line, ' ')))
        return (ERROR);
    while (s[count] != NULL)
        ++count;
    if (count != 2)
    {
        free_split(s);
        return (ERROR);
    }
    if (ft_strcmp(s[0], "F"))
    {
        free_split(s);
        return (ERROR);;
    }
    desc_info->color_f = check_and_get_color(s[1]);
    if (desc_info->color_f == -1)
    {
        free_split(s);
        return (ERROR);;
    }
    free_split(s);
    return (SUCCESS);
}

int get_ceiling_color(char *line, t_desc_info *desc_info)
{
    int count;
    char **s;

    count = 0;
    if (!(s = ft_split(line, ' ')))
        return (ERROR);;
    while (s[count] != NULL)
        ++count;
    if (count != 2)
    {
        free_split(s);
        return (ERROR);;
    }
    if (ft_strcmp(s[0], "C"))
    {
        free_split(s);
        return (ERROR);;
    }
    desc_info->color_c = check_and_get_color(s[1]);
    if (desc_info->color_c == -1)
    {
        free_split(s);
        return (ERROR);;
    }
    free_split(s);
    return (SUCCESS);
}