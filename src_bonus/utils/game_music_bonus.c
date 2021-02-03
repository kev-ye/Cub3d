/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_music_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:44:00 by kaye              #+#    #+#             */
/*   Updated: 2021/02/03 16:03:07 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    game_sound()
{
    system("afplay ./src_bonus/game_music/game_sound.mp3&");
}

void    effect_sound_h()
{
    system("afplay ./src_bonus/game_music/health_sound.wav&");
}

void    effect_sound_m()
{
    system("afplay ./src_bonus/game_music/monster_sound.wav&");
}

void    game_music()
{
    
}