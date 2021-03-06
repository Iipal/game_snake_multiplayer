/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:52:45 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/14 14:23:20 by _ipal            ###   ########.fr       */
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
		case SETTING_WIDTH:
		{
			printf("\tSet width to: ");
			scanf("%hi", &temp.width);
			if (temp.width >= GRID_MIN && temp.width <= GRID_MAX)
			{
				game.width = temp.width;
				system(ECHO_OK("Width settings saved."));
				sleep(1);
			}
			else
			{
				err++;
				system(ECHO_KO("Wrong setting for width."));
				sleep(1);
			}
			break;
		}
		case SETTING_HEIGHT:
		{
			printf("\tSet height to: ");
			scanf("%hi", &temp.height);
			if (temp.height >= GRID_MIN && temp.height <= GRID_MAX)
			{
				game.height = temp.height;
				system(ECHO_OK("Height settings saved."));
				sleep(1);
			}
			else
			{
				err++;
				system(ECHO_KO("Wrong setting for height."));
				sleep(1);
			}
			break;
		}
		case SETTING_NICKNAME:
		{
			printf("\tYour new nickname: ");
			game.nickname = ft_settings_setnickname(game.nickname);
			sleep(1);
			break;
		}
		case SETTING_DEFAULT:
		{
			system(ECHO_OK("Settings is set default, success."));
			ft_settings_default(&game);
			sleep(1);
			break;
		}
	}
	if (!err)
		ft_fsettings_fsave();
	ft_switches_settings(ft_menu_settings());
}

void	ft_settings_default(t_game *def)
{
	def->width		= DEFAULT_GRID_WIDTH;
	def->height		= DEFAULT_GRID_HEIGHT;
	def->nickname	= strdup(DEFAULT_NICKNAME);
}

char	*ft_settings_setnickname(char *nickname)
{
	if ((nickname = (char *)malloc(sizeof(char) * BUFF_SIZE)) != NULL )
	{
		do
		{
			scanf("%s", nickname);
			if (nickname != NULL && *nickname != 0)
				return (nickname);
			else
				system(ECHO_KO("Wrong nickname."));
		} while (1);
	}
	return (NULL);
}

void	ft_settings_user(t_usersets	*us)
{
	t_game	temp;
	char	*tmpnn;

	tmpnn = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (us->USERSETS_WIDTH == 1)
	{
		do
		{
			printf("Set game width (min %d | max %d): ", GRID_MIN, GRID_MAX);
			scanf("%hi", &temp.width);
			if (temp.width >= GRID_MIN && temp.width <= GRID_MAX)
			{
				system(ECHO_OK("OK."));
				game.width = temp.width;
				break;
			}
			else
				system(ECHO_KO("KO."));
		} while (1);
	}
	if (us->USERSETS_HEIGHT == 1)
	{
		do
		{
			printf("Set game height (min %d | max %d): ", GRID_MIN, GRID_MAX);
			scanf("%hi", &temp.height);
			if (temp.height >= GRID_MIN && temp.height <= GRID_MAX)
			{
				system(ECHO_OK("OK."));
				game.height = temp.height;
				break;
			}
			else
				system(ECHO_KO("KO."));
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
				system(ECHO_OK("OK."));
				game.nickname = strdup(tmpnn);
				break;
			}
			else
				system(ECHO_KO("KO."));
		} while (1);
	}
	free(tmpnn);
}
