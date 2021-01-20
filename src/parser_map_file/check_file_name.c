/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:06:12 by kaye              #+#    #+#             */
/*   Updated: 2021/01/20 17:26:53 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_file_name(const char *path)
{
    const char *tmp_path;

    if (!path)
        return (ERROR);
    tmp_path = path;
    if ((path = ft_strrchr(path, '.')) && !ft_strcmp(path, ".cub"))
    {
        path = tmp_path;
        return (SUCCESS);
    }
    return (ERROR);   
}