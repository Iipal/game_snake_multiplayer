/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_processing_moves.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 03:02:14 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/13 04:22:04 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"

short	ft_turn_up(t_snake *snake)
{
	t_direct_point	*head;
	char			body_seg;
	short			success;

	head = &(snake->head);
	success = 1;
	switch (head->dir)
	{
		case LEFT:	body_seg = '\\'; break;
		case RIGHT: body_seg = '/';	 break;
		case DOWN:	success = 0;
		default: goto ret;
	}
	snake->new_dir = UP;
	playfield[head->y][head->x] = body_seg;
ret:
	return (success);
}

short	ft_turn_down(t_snake *snake)
{
	t_direct_point	*head;
	char			body_seg;
	short			success;

	head = &(snake->head);
	success = 1;
	switch (head->dir)
	{
		case LEFT:	body_seg = '/';  break;
		case RIGHT: body_seg = '\\'; break;
		case UP:	success = 0;
		default: goto ret;
	}
	snake->new_dir = DOWN;
	playfield[head->move_y][head->move_x] = body_seg;
ret:
	return (success);
}

short	ft_turn_left(t_snake *snake)
{
	t_direct_point	*head;
	char			body_seg;
	short			success;

	head = &(snake->head);
	success = 1;
	switch (head->dir)
	{
		case UP:	body_seg = '\\'; break;
		case DOWN:	body_seg = '/';  break;
		case RIGHT:	success = 0;
		default: goto ret;
	}
	snake->new_dir = LEFT;
	playfield[head->move_y][head->move_x] = body_seg;
ret:
	return (success);
}

short	ft_turn_right(t_snake *snake)
{
	t_direct_point	*head;
	char			body_seg;
	short			success;

	head = &(snake->head);
	success = 1;
	switch (head->dir)
	{
		case UP:	body_seg = '/';  break;
		case DOWN:	body_seg = '\\'; break;
		case LEFT:	success = 0;
		default: goto ret;
	}
	snake->new_dir = RIGHT;
	playfield[head->move_y][head->move_x] = body_seg;
ret:
	return (success);
}

short	ft_process_key(t_snake *snake)
{
	short	c;
	short	snake_move;

	c = 0;
	snake_move = 0;
	if (read(STDIN_FILENO, &c, 3))
	{
		switch (c)
		{
			case KEY_UP:	snake_move = turn_up(snake);	break;
			case KEY_DOWN:	snake_move = turn_down(snake);	break;
			case KEY_LEFT:	snake_move = turn_left(snake);	break;
			case KEY_RIGHT: snake_mode = turn_right(snake);	break;
		}
	}
	return (snake_move);
}

void	ft_move_snake(t_snake *snake)
{
	t_direct_point	*head;
	t_direct_point	*tail;
	unsigned char	head_ch;

	head = &(snake->head);
	tail = &(snake->tail);
	if (head->dir == snake->new_dir)
		if (head->dir == UP || head->dir == DOWN)
			g_playfield[head->move_y][head->move_x] = '|';
		else
			g_playfield[head->move_y][head->move_x] = '-';
	else
		head->dir = snake->new_dir;
	switch (head->dir)
	{
		case UP:	head->move_y--; head_ch = 'V'; break;
		case DOWN:	head->move_v++; head_ch = '^'; break;
		case LEFT:	head->move_x--; head_ch = '>'; break;
		case RIGHT:	head->move_x++; head_ch = '<'; break;
		default:	assert(0);
	}
	if (head->move_x < 0 || head->move_x >= x||
			head->move_y < 0 || head->move_y >= y)
	{
		ft_reset_input_mode();
		system("echo \"\\e[31mYou hit a wall. GAME OVER!\\e[0m\"");
		printf("Press any key to exit.\n");
		getchar();
		exit(0);
	}
	g_playfield[head->row][head->col] = head_ch;
	if (snake->length_buff)
	{
		snake->length_buff--;
		snake->length++;
	}
	else
	{
		g_playfield[trail->y][trail->x] = ' ';
		switch (tail->dir)
		{
			case UP:	tail->move_y--; break;
			case DOWN:	tail->move_y++; break;
			case LEFT:	tail->move_x--; break;
			case RIGHT:	tail->move_x++; break;
			default:	assert(0);
		}
		switch (g_playfield[tail->y][tail->x])
		{
			case '-': case '|': break;
			case '/':
			{
				switch (tail->dir)
				{
					case UP:	tail->dir = RIGHT;	break;
					case DOWN:	tail->dir = LEFT;	break;
					case LEFT:	tail->dir = DOWN;		break;
					case RIGHT:	tail->dir = UP;	break;
					default:	assert(0);
				}
				break;
			}
			case '\\':
			{
				switch (tail->dir)
				{
					case UP:	tail->dir = LEFT;	break;
					case DOWN:	tail->dir = RIGHT;	break;
					case LEFT:	tail->dir = UP;		break;
					case RIGHT:	tail->dir = DOWN;	break;
					default:	assert(0);
				}
				break;
			}
			default: assert(0);
		}
	}
}
