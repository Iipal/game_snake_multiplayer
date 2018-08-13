/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_fsettings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:31:59 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/14 00:40:23 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_errors.h"
#include "../includes/ft_game.h"
#include "../includes/ft_menu.h"
#include "../includes/ft_settings.h"
#include "../includes/ft_fsettings.h"

void	ft_fswitches_swfread(short fread)
{
	t_usersets	us;

	switch (fread)
	{
		case FT_SUCCESS:
		{
			system("echo \"\\e[32mDone.\\e[0m\"");
			sleep(1);
			ft_switches_main(ft_menu_main());
			break;
		}
		case FT_ERROR:
		{
			system("echo \"\\e[31mKO.\\e[0m\"");
			printf("Problems with file reading.\n");
			ft_fswitches_swfread(ft_fsettings_fread_problem());
			break;
		}
		case SETTING_DEFAULT:
		{
			ft_settings_default(&game);
			system("echo \"\\e[32mDefault settings is apllied.\\e[0m\"");
			sleep(1);
			ft_fsettings_fsave();
			sleep(1);
			ft_switches_main(ft_menu_main());
			break;
		}
		case SETTING_USER:
		{
			us.USERSETS_WIDTH = 1;
			us.USERSETS_HEIGHT = 1;
			us.USERSETS_NICKNAME = 1;
			ft_settings_user(&us);
			sleep(1);
			ft_fsettings_fsave();
			sleep(1);
			ft_switches_main(ft_menu_main());
			break;
		}
	}
}

void	ft_fsettings_fexample(void)
{
	printf("\tSettings file example:\n");
	printf("%s%d\n%s%d\n%s%s\n", FSETTING_FWIDTH, DEFAULT_GRID_WIDTH,
								FSETTING_FHEIGHT, DEFAULT_GRID_HEIGHT,
								FSETTING_FNICKNAME, DEFAULT_NICKNAME);
}

void	ft_fsettings_fread_strparse_data(char *parse, char fp_set)
{
	char	*fp_temp;
	int		i;

	i = 0;
	fp_temp = (char *)malloc(sizeof(char) * 32 + 1);
	while (*parse)
	{
		if (*parse == ':')
		{
			parse++;
			while (*parse && *parse != '\n')
			{
				fp_temp[i++] = *parse;
				parse++;
			}
			fp_temp[i] = '\0';
			switch (fp_set)
			{
				case 'W': game.width = atoi(fp_temp); break;
				case 'H': game.height = atoi(fp_temp); break;
				case 'N': game.nickname = strdup(fp_temp); break;
				default: printf("Someting is wrong...\n"); break;
			}
			break;
		}
		else
			parse++;
	}
	free(fp_temp);
}

void	ft_fsettings_fread_strparse(char *parse)
{
	char		*fp_temp;
	short		err;
	t_usersets	us;

	err = 0;
	if ((fp_temp = strstr(parse, FSETTING_FWIDTH)) != NULL)
		ft_fsettings_fread_strparse_data(fp_temp, 'W');
	else
	{
		err++;
		us.USERSETS_WIDTH = 1;
		system("echo \"\\e[31mWrong settings name for width.\\e[0m\"");
	}
	if ((fp_temp = strstr(parse, FSETTING_FHEIGHT)) != NULL)
		ft_fsettings_fread_strparse_data(fp_temp, 'H');
	else
	{
		err++;
		us.USERSETS_HEIGHT = 1;
		system("echo \"\\e[31mWrong settings name for height.\\e[0m\"");
	}
	if ((fp_temp = strstr(parse, FSETTING_FNICKNAME)) != NULL)
		ft_fsettings_fread_strparse_data(fp_temp, 'N');
	else
	{
		err++;
		us.USERSETS_NICKNAME = 1;
		system("echo \"\\e[31mWrong settings name for nickname\\e[0m\"");
	}
	if (err)
	{
		ft_fsettings_fexample();
		sleep(2);
		ft_settings_user(&us);
	}
}

short	ft_fsettings_fread(void)
{
	FILE	*readfile;
	long	rf_size;
	long	rf_res;
	char	*rf_buff;

	rf_size = 0;
	if ((readfile = fopen(FSETTING_FILENAME, "r")) != NULL)
	{
		fseek(readfile, 0, SEEK_END);
		rf_size = ftell(readfile);
		rewind(readfile);
		if ((rf_buff = (char *)malloc(sizeof(char) * rf_size)) != NULL)
			if ((rf_res = fread(rf_buff, 1, rf_size, readfile)) == rf_size)
				if (rf_buff != NULL && *rf_buff != 0)
					ft_fsettings_fread_strparse(rf_buff);
				else
					return (FT_ERROR);
			else
				return (FT_ERROR);
		else
			return (FT_ERROR);
		free(rf_buff);
	}
	else
	{
		system("echo \"\\e[31mSettings file doesn't exist.\\e[0m\"");
		ft_fswitches_swfread(ft_fsettings_fread_problem());
	}
	fclose(readfile);
	return (FT_SUCCESS);
}

short	ft_fsettings_fread_problem(void)
{
	char	setsettings;

	setsettings = 0;
	sleep(1);
	while (1)
	{
		printf("Apply default settings ?(Y/n): ");
		do
		{
			setsettings = getchar();
			switch (setsettings)
			{
				case 'y': case 'Y': return (SETTING_DEFAULT);
				case 'n': case 'N': return (SETTING_USER);
				default: system("echo \"\\e[31mKO.\\e[0m\""); break;
			}
		} while (1);
	}
	return (FT_ERROR);
}

void	ft_fsettings_fsave(void)
{
	FILE	*savefile;

	if ((savefile = fopen(FSETTING_FILENAME, "wb+")) != NULL)
	{
		fprintf(savefile, "\t\"Snake\" settings file.\n");
		fprintf(savefile, "%s%hi\n", FSETTING_FWIDTH, game.width);
		fprintf(savefile, "%s%hi\n", FSETTING_FHEIGHT, game.height);
		fprintf(savefile, "%s%s\n", FSETTING_FNICKNAME, game.nickname);
		system("echo \"\\e[32mSettings saved.\\e[0m\"");
		sleep(1);
	}
	else
	{
		system("echo \"\\e[31mCannot open or create settings file.\\e[0m\"");
		sleep(1);
	}
	fclose(savefile);
}
