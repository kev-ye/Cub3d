/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:56:10 by kaye              #+#    #+#             */
/*   Updated: 2021/02/08 11:21:19 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void			free_split(char **s)
{
	int count;

	count = 0;
	while (s[count] != NULL)
		free(s[count++]);
	free(s[count]);
	free(s);
}

static void		free_path(t_desc_info *desc_info)
{
	if (desc_info->path_no)
		free(desc_info->path_no);
	if (desc_info->path_so)
		free(desc_info->path_so);
	if (desc_info->path_we)
		free(desc_info->path_we);
	if (desc_info->path_ea)
		free(desc_info->path_ea);
	if (desc_info->path_s)
		free(desc_info->path_s);
	if (desc_info->path_s)
		free(desc_info->path_m);
	if (desc_info->path_s)
		free(desc_info->path_b);
	if (desc_info->path_s)
		free(desc_info->path_l);
	if (desc_info->path_s)
		free(desc_info->path_g);
}

void			free_desc_info(t_desc_info *desc_info)
{
	int i;

	i = 0;
	free_path(desc_info);
	if (desc_info->map)
	{
		while (i < desc_info->map_y)
		{
			if (desc_info->map[i])
				free(desc_info->map[i]);
			i++;
		}
		free(desc_info->map);
	}
	free(desc_info);
}

static void		free_img(t_win *win)
{
	if (win->texture != NULL)
	{
		if (win->texture[0] != NULL)
			free(win->texture[0]);
		if (win->texture[1] != NULL)
			free(win->texture[1]);
		if (win->texture[2] != NULL)
			free(win->texture[2]);
		if (win->texture[3] != NULL)
			free(win->texture[3]);
		free(win->texture);
	}
	if (win->sprite != NULL)
	{
		if (win->sprite[0] != NULL)
			free(win->sprite[0]);
		if (win->sprite[1] != NULL)
			free(win->sprite[1]);
		if (win->sprite[2] != NULL)
			free(win->sprite[2]);
		free(win->sprite);
	}
}

void			free_win(t_win *win)
{
	if (win->key_code != NULL)
		free(win->key_code);
	if (win->img != NULL)
		free(win->img);
	if (win->camera != NULL)
		free(win->camera);
	if (win->desc_info != NULL)
		free_desc_info(win->desc_info);
	free_img(win);
	if (win != NULL)
		free(win);
}
