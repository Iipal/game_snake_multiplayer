/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:21:54 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/09 10:42:43 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define GRIDMIN 10
# define GRIDMAX 30
# define SPEEDMIN 1
# define SPEEDMAX 5

# define FTERROR -1
# define FTSUCCESS 0
# define FTDONE 1

# define DEFAULTGRID 12
# define DEFAULTSPEED 3
# define DEFAULTNICKNAME "Player 1"

typedef struct	s_game
{
	short	grid_x;
	short	grid_y;
	short	speed;
	char	*nickname;
}				t_game;

typedef enum	e_mainmenu
{
	MAINMENUEXIT,
	MAINGAMEMODE,
	MAINSETTINGS
}				t_mainmenu;

typedef enum	e_mode
{
	MODEEXIT,
	MODESOLO,
	MODEBOT,
	MODEPVP
}				t_mode;

typedef enum	e_settings
{
	SETTINGEXIT,
	SETTINGGRIDX,
	SETTINGGRIDY,
	SETTINGSPEED,
	SETTINGNICKNAME,
	SETTINGDEFAULT
}				t_settings;

typedef enum	e_err
{
	ERRX = -1,
	ERRY = -2,
	ERRSPEED = -3,
	ERRNICKNAME = -4
}				t_err;

t_game		game;
t_mainmenu	mainmenu;
t_mode		modemenu;
t_settings	settingsmenu;
t_err		errors;

void	ft_game_solo();
void	ft_game_bot();
void	ft_game_pvp();

#endif
