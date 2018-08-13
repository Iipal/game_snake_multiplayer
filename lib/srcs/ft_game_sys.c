/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_sys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 02:44:38 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/13 13:20:40 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"

void	ft_reset_input_mode(void)
{
	printf("\x1b[?25h");
	tcsetattr(STDIN_FILENO, TCSANOW, &g_saved_attributes);
	system("clear");
}

void	ft_sighandler(int sig)
{
	g_run = 0;
	signal(sig, ft_sighandler);
}

void	ft_set_terminal_mode(void)
{
	struct termios	t_attr;
	
	setbuf(stdout, NULL);
	if (!isatty(STDIN_FILENO))
	{
		fprintf(stderr, "Not a terminal.\n");
		exit(EXIT_FAILURE);
	}
	tcgetattr(STDIN_FILENO, &g_saved_attributes);
	tcgetattr(STDIN_FILENO, &t_attr);
	t_attr.c_lflag &= ~(ICANON|ECHO);
	t_attr.c_cc[VMIN] = 0;
	t_attr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &t_attr);
	printf("\x1b[?25l");
	system("clear");
	atexit(ft_reset_input_mode);
}
