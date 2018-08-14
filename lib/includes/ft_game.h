/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:21:54 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/14 17:52:57 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# include <termios.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <assert.h>
# include <signal.h>
# include <stdio.h>
# include <time.h>

enum
{
	KEY_UP 		= 0x415b1b,
	KEY_DOWN 	= 0x425b1b,
	KEY_RIGHT 	= 0x435b1b,
	KEY_LEFT 	= 0x445b1b
};

enum
{
	BILLION = 1000000000,
	FOOD_RARITY = 512,
	LVLUP_LENGTH = 50
};

typedef struct	s_game
{
	short		width;
	short		height;
	char		*nickname;
}				t_game;

typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}				t_direct;

typedef	struct	s_direct_point
{
	short		move_x;
	short		move_y;
	t_direct	dir;
}				t_direct_point;

typedef struct	s_snake
{
	t_direct_point	head;
	t_direct_point	tail;
	t_direct		new_dir;
	unsigned long	length;
	unsigned long	length_buff;
}				t_snake;

typedef struct	s_pos
{
	short	x;
	short	y;
}				t_pos;

t_game			game;
t_pos			pos;
sig_atomic_t	g_run;
struct termios	g_saved_attributes;
unsigned short	g_food_counter;
unsigned short	g_level;

short 	ft_turn_up(t_snake *snake, char **g_playfield);
short	ft_turn_down(t_snake *snake, char **g_playfield);
short	ft_turn_left(t_snake *snake, char **g_playfield);
short	ft_turn_right(t_snake *snake, char **g_playfield);
short	ft_process_key(t_snake *snake, char **g_playfield);

void	ft_start_solo(void);
void	ft_game_solo(void);
void	ft_game_bot(void);
void	ft_game_pvp(void);

void	ft_reset_input_mode(void);
void	ft_sighandler(int sig);
void	ft_set_terminal_mode(void);

void	ft_init_playfield(char **g_playfield);
void	ft_init_snake(t_snake *snake, char **g_playfield);
void	ft_redraw_all(t_snake *snake, char **g_playfield);
void	ft_redraw_animation(t_snake *snake, char **playfield);
void	ft_move_snake(t_snake *snake, char **g_playfield);

void	ft_generate_food(char **g_playfield);
void	ft_level_up(t_snake *snake);

#endif
