/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:21:54 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/13 13:19:55 by _ipal            ###   ########.fr       */
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

# define BILLION		1000000000

# define KEY_UP			0x415b1b
# define KEY_DOWN		0x425b1b
# define KEY_RIGHT		0x435b1b
# define KEY_LEFT		0x445b1b

# define FOOD_RARITY	512
# define LVLUP_LENGTH	50

typedef struct	s_game
{
	short		width;
	short		height;
	short		speed;
	char		*nickname;
}				t_game;

typedef enum	e_direct
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
	unsigned short	length;
	unsigned short	length_buff;
}				t_snake;

typedef	struct	s_pos
{
	short	x;
	short	y;
}				t_pos;

t_game			game;
t_pos			pos;
sig_atomic_t	g_run = 1;
struct termios	g_saved_attributes;
unsigned char	g_playfield[pos.x][pos.y];
unsigned short	g_food_counter = 0;
unsigned short	g_level = 1;

short 	ft_turn_up(t_snake *snake);
short	ft_turn_down(t_snake *snake);
short	ft_turn_left(t_snake *snake);
short	ft_turn_right(t_snake *snake);
short	ft_process_key(t_snake *snake);

void	ft_game_solo(void);
void	ft_game_bot(void);
void	ft_game_pvp(void);

void	ft_reset_input_mode(void);
void	ft_sighandler(int sig);
void	ft_set_terminal_mode(void);
void	ft_init_playfield(void);
void	ft_init_snake(t_snake *snake);
void	ft_redraw_all(t_snake *snake);
void	ft_redraw_animation(t_snake *snake);
void	ft_move_snake(t_snake *snake);
void	ft_generate_food(void);
void	ft_level_up(t_snake *snake);

#endif
