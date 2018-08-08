/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:21:54 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/08 14:38:35 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_game
{
	short	grid_x;
	short	grid_y;
	short	speed;
	char	*nickname;
}				t_game;

t_game	game;

void	ft_set_nickname();
void	ft_game_solo();
void	ft_game_solorules();
void	ft_game_bot();
void	ft_game_botrules();
void	ft_game_pvp();
void	ft_game_pvprules();

#endif
