/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_music_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:44:00 by kaye              #+#    #+#             */
/*   Updated: 2021/02/04 16:01:48 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    game_sound()
{
    system(SOUND" ./src_bonus/game_music/game_sound.wav 2>/dev/null&");
}

void    effect_sound_h()
{
    system(SOUND" ./src_bonus/game_music/health_sound.wav 2>/dev/null&");
}

void    effect_sound_m()
{
    system(SOUND" ./src_bonus/game_music/monster_sound.wav 2>/dev/null&");
}

void    play_game_sound(t_win *win)
{
    game_sound();
    win->sound_begin_time = clock();
}

void    game_sound_loop(t_win *win)
{
    clock_t time;

    time = clock();
    if (((double)(time - win->sound_begin_time) / CLOCKS_PER_SEC) > 12)
    {
        system(KILL_SOUND);
        game_sound();
        win->sound_begin_time = time;
    }
}