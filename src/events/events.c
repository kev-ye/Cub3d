/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:01:56 by kaye              #+#    #+#             */
/*   Updated: 2021/02/08 13:08:09 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		need_casting(t_win *win)
{
	if (win->key_code->key_w == 1 || win->key_code->key_s == 1 ||
			win->key_code->key_a == 1 || win->key_code->key_d == 1 ||
			win->key_code->key_left == 1 || win->key_code->key_right == 1)
		win->need_casting = 1;
	else
		win->need_casting = 0;
}

int				event_loop(t_win *win)
{
	if (!(ray_casting(win)))
		shut_down(win);
	event_key(win);
	need_casting(win);
	return (1);
}

int				event_destroy_win(t_win *win)
{
	shut_down(win);
	return (1);
}
