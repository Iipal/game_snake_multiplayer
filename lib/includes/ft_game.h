/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:21:54 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/09 22:41:57 by _ipal            ###   ########.fr       */
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

t_game		game;

void	ft_game_solo();
void	ft_game_bot();
void	ft_game_pvp();

#endif
