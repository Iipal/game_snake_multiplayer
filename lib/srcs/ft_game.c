/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 22:15:07 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/13 13:05:50 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"

void	ft_game_solo()
{
	ft_set_terminal_mode();
	signal(SIGINT, ft_sighandler);
	srand(time(NULL));

	t_snake			snake0;
	struct timespec	time_start;
	struct timespec	time_now;
	long long		time_delta;
	char			animate;
	short			snake_moved;

	pos.x = game.width - 2;
	pos.y = game.height - 3;
	animate = 1;
	snake_moved = 0;
	ft_init_playfield();
	ft_init_snake(&snake0);
	clock_gettime(CLOCK_REALTIME, &time_start);
	while (g_run)
	{
		snake_moved = ft_process_key(&snake0);

		clock_gettime(CLOCK_REALTIME, &time_now);
		time_delta = ((time_now.tv_sec - time_start.tv_sec) * BILLION +
						(time_now.tv_nsec - time_start.tv_nsec));
		if (snake_moved ||
				time_delta > BILLION / (g_level + 1) / 5)
		{
			time_start = time_now;
			if (animate)
			{
				ft_redraw_animation(&snake0);
				animate = 0;
			}
			else
			{
				snake_moved = 0;
				ft_generate_food();
				ft_level_up(&snake0);
				ft_move_snake(&snake0);
				ft_redraw_all(&snake0);
				animate = 1;
			}
		}
	}
	exit(EXIT_SUCCESS);
}
