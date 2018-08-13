/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_initial_n_drawing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 03:27:58 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/13 13:26:25 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"

void	ft_init_playfield(void)
{
	for (int j = 0; j < pos.y; j++)
		for (int i = 0; i < pos.x; g_playfield[j][i++] = ' ');
}

void	ft_init_snake(t_snake *snake)
{
	g_playfield[pos.y / 2][pos.x / 2] = '<';
	snake->head.move_x = pos.y / 2;
	snake->head.move_y = pos.x / 2;
	snake->head.dir = RIGHT;
	snake->tail.move_x = pos.x / 2;
	snake->tail.move_y = pos.y / 2;
	snake->tail.dir = RIGHT;
	snake->new_dir = RIGHT;
	snake->length = 1;
	snake->length_buff = 4;
}

void	ft_redraw_all(t_snake *snake)
{
	printf("\x1b[H");
	for (int i = pos.x + 2; i; i--)
		putchar('#');
	putchar('\n');
	for (int j = 0; j < pos.y; j++)
	{
		putchar('#');
		for (int i = 0; i < pos.x; i++)
			putchar(g_playfield[j][i]);
		putchar('#');
		putchar('\n');
	}
	for (int i = pos.x + 2; i; i--)
		putchar('#');
	putchar('\n');
	printf("Player: %s\tLength: %5d\tLevel: %3d", game.nickname, snake->length, g_level);
}

void	ft_redraw_animation(t_snake *snake)
{
	printf("\x1b[%d;%dH", snake->head.move_x + 2, snake->head.move_y + 2);
	if (g_playfield[snake->tail.move_y][snake->tail.move_x] != '-' &&
			g_playfield[snake->tail.move_y][snake->tail.move_x] != '|')
	{
		if (snake->head.dir == UP ||
				snake->head.dir == DOWN)
			putchar('|');
		else
			putchar('-');
	}
}
