/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:52:45 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/08 15:21:20 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"
#include "../includes/ft_menu.h"
#include "../includes/ft_settings.h"


void	ft_settings_change(short setting)
{
	t_game	temp;
	short	err;

	err = 0;
	if (setting == 1)
	{
		printf("\tSet X to: ");
		scanf("%hi", &temp.grid_x);
		if (temp.grid_x >= 10 && temp.grid_x <= 30)
			game.grid_x = temp.grid_x;
		else
		{
			err++;
			system("clear");
			system("echo \"\\e[31mWrong value for X.\\e[0m\"");
			sleep(1);
		}
	}
	else if (setting == 2)
	{
		printf("\tSet Y to: ");
		scanf("%hi", &temp.grid_y);
		if (temp.grid_y >= 10 && temp.grid_y <= 30)
			game.grid_y = temp.grid_y;
		else
		{
			err++;
			system("clear");
			system("echo \"\\e[31mWrong value for Y.\\e[0m\"");
			sleep(1);
		}
	}
	else if (setting == 3)
	{
		printf("\tSet game speed to: ");
		scanf("%hi", &temp.speed);
		if (temp.speed >= 1 && temp.speed <= 5)
			game.speed = temp.speed;
		else
		{
			err++;
			system("clear");
			system("echo \"\\e[31mWrong value for game speed.\\e[0m\"");
			sleep(1);
		}
	}
	else if (setting == 4)
	{
		printf("\tYour new nickname: ");
		scanf("%s", temp.nickname);
		if (temp.nickname)
			game.nickname = strdup(temp.nickname);
		else
		{
			err++;
			system("clear");
			system("echo \"\\e[31mWrong nickname.\\e[0m\"");
			sleep(1);
		}
	}
	else if (setting == 5)
		ft_settings_default();
	if (err == 0)
		ft_settings_save();
	ft_settings_menu();
}

void	ft_settings_default()
{
	game.grid_x = 10;
	game.grid_y = 10;
	game.speed = 3;
	game.nickname = "Player1";
}

void	ft_settings_save()
{
	FILE	*config;

	if ((config = fopen("config", "wb+")) != NULL)
	{
		fprintf(config, "X: %hi\n", game.grid_x);
		fprintf(config, "Y: %hi\n", game.grid_y);
		fprintf(config, "S: %hi\n", game.speed);
		fprintf(config, "N: %s", game.nickname);
		system("clear");
		system("echo \"\\e[32mSettings saved.\\e[0m\"");
		sleep(1);
	}
	else
	{
		system("clear");
		system("echo \"\\e[31mCannot open the config file.\\e[0m\"");
		sleep(1);
	}
	fclose(config);
}
