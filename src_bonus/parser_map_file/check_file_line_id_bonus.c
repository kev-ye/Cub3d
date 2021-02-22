/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_line_id_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:11:45 by kaye              #+#    #+#             */
/*   Updated: 2021/02/22 21:04:33 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int		check_file_line_info_4(
		char *line,
		int i,
		t_desc **desc,
		t_desc_info *desc_info)
{
	if (line[i] == 'L' && line[i + 1] == ' ')
	{
		if (!(get_path(line, desc_info)))
			return (0);
		(*desc)->l++;
	}
	else if (line[i] == 'M' && line[i + 1] == ' ')
	{
		if (!(get_path(line, desc_info)))
			return (0);
		(*desc)->m++;
	}
	else if (line[i] == 'G' && line[i + 1] == ' ')
	{
		if (!(get_path(line, desc_info)))
			return (0);
		(*desc)->g++;
	}
	else
		return (0);
	return (1);
}

static int		check_file_line_info_3(
		char *line,
		int i,
		t_desc **desc,
		t_desc_info *desc_info)
{
	if (line[i] == 'W' && !ft_strncmp((line + i), "WE", 2))
	{
		if (!(get_path(line, desc_info)))
			return (0);
		(*desc)->we++;
	}
	else if (line[i] == 'E' && !ft_strncmp((line + i), "EA", 2))
	{
		if (!(get_path(line, desc_info)))
			return (0);
		(*desc)->ea++;
	}
	else if (line[i] == 'B' && line[i + 1] == ' ')
	{
		if (!(get_path(line, desc_info)))
			return (0);
		(*desc)->b++;
	}
	else if (!(check_file_line_info_4(line, i, desc, desc_info)))
		return (0);
	return (1);
}

static int		check_file_line_info_2(
		char *line,
		int i,
		t_desc **desc,
		t_desc_info *desc_info)
{
	if (line[i] == 'C' && line[i + 1] == ' ')
	{
		if (!(get_ceiling_color(line, desc_info)))
			return (0);
		(*desc)->c++;
	}
	else if (line[i] == 'N' && !ft_strncmp((line + i), "NO", 2))
	{
		if (!(get_path(line, desc_info)))
			return (0);
		(*desc)->no++;
	}
	else if (line[i] == 'S' && !ft_strncmp((line + i), "SO", 2))
	{
		if (!(get_path(line, desc_info)))
			return (0);
		(*desc)->so++;
	}
	else if (!(check_file_line_info_3(line, i, desc, desc_info)))
		return (0);
	return (1);
}

static int		check_file_line_info(
		char *line,
		int i,
		t_desc *desc,
		t_desc_info *desc_info)
{
	if (line[i] == 'R' && line[i + 1] == ' ')
	{
		if (!(get_resoltion(line, desc_info)))
			return (0);
		desc->r++;
	}
	else if (line[i] == 'S' && line[i + 1] == ' ')
	{
		if (!(get_path(line, desc_info)))
			return (0);
		desc->s++;
	}
	else if (line[i] == 'F' && line[i + 1] == ' ')
	{
		if (!(get_floor_color(line, desc_info)))
			return (0);
		desc->f++;
	}
	else if (!(check_file_line_info_2(line, i, &desc, desc_info)))
		return (0);
	return (1);
}

int				check_file_line(
		char *line,
		t_desc *desc,
		t_desc_info *desc_info)
{
	int i;

	if (!*line)
		return (1);
	i = 0;
	if (line[i] == 'R' || line[i] == 'S' || line[i] == 'F' ||
			line[i] == 'N' || line[i] == 'W' || line[i] == 'E' ||
			line[i] == 'C' || line[i] == 'B' || line[i] == 'L' ||
			line[i] == 'M' || line[i] == 'G')
	{
		if (check_file_line_info(line, i, desc, desc_info)
				&& check_file_line_info_done(*desc))
			return (1);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}
