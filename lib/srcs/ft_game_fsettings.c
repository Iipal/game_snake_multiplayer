/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_fsettings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:38:37 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/09 10:26:47 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"

void	ft_settings_fchange(short setting, void *value)
{
	t_game	temp;

	if (setting == SETTINGGRIDX)
	{
		temp.grid_x = *((short *)value);
		if (temp.grid_x >= GRIDMIN && temp.grid_x <= GRIDMAX)
		{
			game.grid_x = temp.grid_x;
			printf("X settings is ");
			system("echo -n \"\e[32mOK.\\e[0m\"");
			printf(" (%hi)\n", game.grid_x);
			sleep(1);
		}
		else
		{
			printf("Wrong settings for X. ");
			system("echo \"\\e[31mKO.\\e[0m\"");
			printf(" (%hi)\n", game.grid_x);
			printf("We will set default settings for X.\n");
			sleep(1);
			game.grid_x = DEFAULTGRID;
		}
	}
	if (setting == SETTINGGRIDY)
	{
		temp.grid_y = *((short *)value);
		if (temp.grid_y >= GRIDMIN && temp.grid_x <= GRIDMAX)
		{
			game.grid_y = temp.grid_y;
			printf("Y settings is ");
			system("echo -n \"\\e[32mOK.\\e[0m\"");
			printf(" (%hi)\n", game.grid_y);
			sleep(1);
		}
		else
		{
			printf("Wrong settings for Y. ");
			system("echo -n \"\\e[31mKO.\\e[0m\"");
			printf(" (%hi)\n", game.grid_y);
			printf("We will set default settings for Y.\n");
			sleep(1);
			game.grid_y = DEFAULTGRID;
		}
	}
	if (setting == SETTINGSPEED)
	{
		temp.speed = *((short *)value);
		if (temp.speed >= SPEEDMIN && temp.speed <= SPEEDMAX)
		{
			game.speed = temp.speed;
			printf("Game speed settings is ");
			system("echo -n \"\\e[32mOK.\\e[0m\"");
			printf(" (%hi)\n", game.speed);
			sleep(1);
		}
		else
		{
			printf("Wrong settings for game speed. ");
			system("echo \"\\e[31mKO.\\e[0m\"");
			printf(" (%hi)\n", game.speed);
			printf("We will set default settings for speed.\n");
			sleep(1);
			game.speed = DEFAULTSPEED;
		}
	}
	if (setting == SETTINGNICKNAME)
	{
		game.nickname = ((char *)value);
		printf("We change your nickname.\n");
	}
}

short	ft_settings_fread_parse(char *buff, char fsetting)
{
	char	*temp;
	int		i;

	i = 0;
	if ((temp = (char *)malloc(sizeof(char) * 64 + 1)) != NULL)
	{
		while (*buff != '\n' || *buff != '\0')
		{
			temp[i] = *buff;
			buff++;
			i++;
		}
		temp[i] = '\0';
		if (fsetting == 'X')
			ft_settings_fchange(SETTINGGRIDX, &atoi(temp));
		else if (fsetting == 'Y')
			ft_settings_fchange(SETTINGGRIDY, atoi(temp));
		else if (fsetting == 'S')
			ft_settings_fchange(SETTINGSPEED, atoi(temp));
		else if (fsetting == 'N')
			ft_settings_fchange(SETTINGNICKNAME, (void *)temp);
		free(temp);
		return (FTDONE);
	}
	return (FTSUCCESS);
}

short	ft_settings_freadf(char *buff)
{
	while (*buff)
	{
		if (*buff == 'X')
			if (ft_settings_fread_parse(buff + 2, 'X'))
				return (ERRX);
		if (*buff == 'Y')
			if (ft_settings_fread_parse(buff + 2, 'Y'))
				return (ERRY);
		if (*buff == 'S')
			if (ft_settings_fread_parse(buff + 2, 'S'))
				return (ERRSPEED);
		if (*buff == 'N')
			if (ft_settings_fread_parse(buff + 2, 'N'))
				return (ERRNICKNAME);
		buff++;
	}
	return (FTSUCCESS);
}

short	ft_settings_fread()
{
	FILE	*config;
	char	*buff;
	short	err;

	err = 0;
	buff = (char *)malloc(sizeof(char) * 128);
	if ((config = fopen("config", "r")) != NULL)
	{
		fgets(buff, 128, config);
		ft_settings_freadf(buff);
	}
	else
	{
		err++;
		system("clear");
		system("echo \"\\e[32mConfig file doesn't exist. Set default settings.\\e[0m\"");
	}
	fclose(config);
	free(buff);
	if (err)
		return (FTERROR);
	return (FTSUCCESS);
}
