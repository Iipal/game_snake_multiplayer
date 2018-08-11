/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:52:45 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/11 22:01:22 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_errors.h"
#include "../includes/ft_game.h"
#include "../includes/ft_menu.h"
#include "../includes/ft_settings.h"
#include "../includes/ft_fsettings.h"

void	ft_settings_change(short setting)
{
	t_game	temp;
	short	err;

	err = 0;
	switch(setting)
	{
		case SETTING_GRID_X:
		{
			printf("\tSet X to: ");
			scanf("%hi", &temp.grid_x);
			if (temp.grid_x >= GRID_MIN && temp.grid_x <= GRID_MAX)
			{
				game.grid_x = temp.grid_x;
				system("echo \"\\e[32mSetting for X saved.\\e[0m\"");
				sleep(1);
			}
			else
			{
				err++;
				system("echo \"\\e[31mWrong setting for X.\\e[0m\"");
				sleep(1);
			}
			break;
		}
		case SETTING_GRID_Y:
		{
			printf("\tSet Y to: ");
			scanf("%hi", &temp.grid_y);
			if (temp.grid_y >= GRID_MIN && temp.grid_y <= GRID_MAX)
			{
				game.grid_y = temp.grid_y;
				system("echo \"\\e[32mSetting for Y saved.\\e[0m\"");
				sleep(1);
			}
			else
			{
				err++;
				system("echo \"\\e[31mWrong setting for X.\\e[0m\"");
				sleep(1);
			}
			break;
		}
		case SETTING_SPEED:
		{
			printf("\tSet game speed to: ");
			scanf("%hi", &temp.speed);
			if (temp.speed >= SPEED_MIN && temp.speed <= SPEED_MAX)
			{
				game.speed = temp.speed;
				system("echo \"\\e[32mSetting for game speed saved.\\e[0m\"");
				sleep(1);
			}
			else
			{
				err++;
				system("echo \"\\e[31mWrong setting for game speed.\\e[0m\"");
				sleep(1);
			}
			break;
		}
		case SETTING_NICKNAME:
		{
			printf("\tYour new nickname: ");
			game.nickname = ft_settings_setnickname(game.nickname, SETTING_USER);
			sleep(1);
			break;
		}
		case SETTING_DEFAULT:
		{
			system("echo \"e[32mSettings is set default, success.\\e[0m\"");
			ft_settings_default(&game);
			sleep(1);
			break;
		}
	}
	if (!err)
		ft_fsettings_fsave();
	ft_switches_settings(ft_menu_settings());
}

char	*ft_settings_setnickname(char *nickname, short setmode)
{
	if ((nickname = (char *)malloc(sizeof(char) * strlen(nickname) + 1)) != NULL)
	{
		switch (setmode)
		{
			case SETTING_USER:
			{
				do
				{
					scanf("%s", nickname);
					if (nickname != NULL && *nickname != 0)
						return (nickname);
					else
						system("echo \"\\e[31mWrong nickname.\\e[0m\"");
				} while (1);
			}
			case SETTING_DEFAULT: return (DEFAULT_NICKNAME);
			default: printf("Something wrong!\n"); break;
		}
	}
	return (NULL);
}

void	ft_settings_default(t_game *def)
{
	def->grid_x = DEFAULT_GRID;
	def->grid_y = DEFAULT_GRID;
	def->speed = DEFAULT_SPEED;
	def->nickname = ft_settings_setnickname(def->nickname, SETTING_DEFAULT);
}

void	ft_settings_user(t_usersets	*us)
{
	t_game	temp;
	char	*tmpnn;

	tmpnn = (char *)malloc(sizeof(char) * 128);
	if (us->USERSETS_GRIDX == 1)
	{
		do
		{
			printf("Set grid size X: ");
			scanf("%hi", &temp.grid_x);
			if (temp.grid_x >= GRID_MIN && temp.grid_x <= GRID_MAX)
			{
				system("echo \"\\e[32mOK.\\e[0m\"");
				game.grid_x = temp.grid_x;
				break;
			}
			else
				system("echo \"\\e[31mKO.\\e[0m\"");
		} while (1);
	}
	if (us->USERSETS_GRIDY == 1)
	{
		do
		{
			printf("Set grid size Y: ");
			scanf("%hi", &temp.grid_y);
			if (temp.grid_y >= GRID_MIN && temp.grid_y <= GRID_MAX)
			{
				system("echo \"\\e[32mOK.\\e[0m\"");
				game.grid_y = temp.grid_y;
				break;
			}
			else
				system("echo \"\\e[31mKO.\\e[0m\"");
		} while (1);
	}
	if (us->USERSETS_SPEED == 1)
	{
		do
		{
			printf("Set game speed: ");
			scanf("%hi", &temp.speed);
			if (temp.speed >= SPEED_MIN && temp.speed <= SPEED_MAX)
			{
				system("echo \"\\e[32mOK.\\e[0m\"");
				game.speed = temp.speed;
				break;
			}
			else
				system("echo \"\\e[31mKO.\\e[0m\"");
		} while (1);
	}
	if (us->USERSETS_NICKNAME == 1)
	{
		do
		{
			printf("Set your nickname: ");
			scanf("%s", tmpnn);
			if (tmpnn[0] != '\0' && tmpnn != 0)
			{
				system("echo \"\\e[32mOK.\\e[0m\"");
				game.nickname = strdup(tmpnn);
				break;
			}
			else
			system("echo \"\\e[31mKO.\\e[0m\"");
		} while (1);
	}
	free(tmpnn);
}
