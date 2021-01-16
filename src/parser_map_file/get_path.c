/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:04:26 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 18:04:44 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int get_path_2(char **s, t_desc_info **desc_info)
{
    char *tmp;
    if (!ft_strncmp(s[0], "NO", 2))
    {
        (*desc_info)->path_no = ft_strdup(s[1]);
        return (SUCCESS);
    }
    else if (!ft_strncmp(s[0], "SO", 2))
    {
        (*desc_info)->path_so = ft_strdup(s[1]);
        return (SUCCESS);
    }
    else if (!ft_strncmp(s[0], "WE", 2))
    {
        (*desc_info)->path_we = ft_strdup(s[1]);
        return (SUCCESS);
    }
    else if (!ft_strncmp(s[0], "EA", 2))
    {
        (*desc_info)->path_ea = ft_strdup(s[1]);
        return (SUCCESS);
    }
    else if (!ft_strcmp(s[0], "S"))
    {
        (*desc_info)->path_s = ft_strdup(s[1]);
        return (SUCCESS);
    }
    return (ERROR);
}

int get_path(char *line, t_desc_info *desc_info)
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
    if (!get_path_2(s, &desc_info))
    {
        free_split(s);
        return (ERROR);;
    }
    free_split(s);
    return (SUCCESS);
}