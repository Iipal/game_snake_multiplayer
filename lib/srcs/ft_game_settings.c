/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:52:45 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/09 10:46:40 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"
#include "../includes/ft_menu.h"
#include "../includes/ft_settings.h"


void	ft_settings_change(short setting)
{
	t_game	temp;
	short	err;

	ft_settings_default(&temp);
	err = 0;
	if (setting == SETTINGGRIDX)
	{
		printf("\tSet X to: ");
		scanf("%hi", &temp.grid_x);
		if (temp.grid_x >= GRIDMIN && temp.grid_x <= GRIDMAX)
			game.grid_x = temp.grid_x;
		else
		{
			err++;
			system("clear");
			system("echo \"\\e[31mWrong value for X.\\e[0m\"");
			sleep(1);
		}
	}
	else if (setting == SETTINGGRIDY)
	{
		printf("\tSet Y to: ");
		scanf("%hi", &temp.grid_y);
		if (temp.grid_y >= GRIDMIN && temp.grid_y <= GRIDMAX)
			game.grid_y = temp.grid_y;
		else
		{
			err++;
			system("clear");
			system("echo \"\\e[31mWrong value for Y.\\e[0m\"");
			sleep(1);
		}
	}
	else if (setting == SETTINGGRIDX)
	{
		printf("\tSet game speed to: ");
		scanf("%hi", &temp.speed);
		if (temp.speed >= SPEEDMIN && temp.speed <= SPEEDMAX)
			game.speed = temp.speed;
		else
		{
			err++;
			system("clear");
			system("echo \"\\e[31mWrong value for game speed.\\e[0m\"");
			sleep(1);
		}
	}
	else if (setting == SETTINGNICKNAME)
	{
		printf("\tYour new nickname: ");
		scanf("%s", temp.nickname);
		if (temp.nickname)
			game.nickname = temp.nickname;
		else
		{
			err++;
			system("clear");
			system("echo \"\\e[31mWrong nickname.\\e[0m\"");
			sleep(1);
		}
	}
	else if (setting == SETTINGDEFAULT)
		ft_settings_default(&game);
	if (!err)
		ft_settings_fsave();
	ft_switches_settings(ft_menu_settings());
}

void	ft_settings_default(t_game *def)
{
	def->grid_x = DEFAULTGRID;
	def->grid_y = DEFAULTGRID;
	def->speed = DEFAULTSPEED;
	def->nickname = (char *)malloc(sizeof(char) * 64);
	def->nickname = DEFAULTNICKNAME;
}

void	ft_settings_fsave()
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
		system("echo \"\\e[31mCannot open or create the config file.\\e[0m\"");
		sleep(1);
	}
	fclose(config);
}
