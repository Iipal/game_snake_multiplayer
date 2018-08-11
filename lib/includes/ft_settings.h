/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:51:03 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/11 22:02:58 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SETTINGS_H
# define FT_SETTINGS_H

# define GRID_MIN 10
# define GRID_MAX 30
# define SPEED_MIN 1
# define SPEED_MAX 5

# define DEFAULT_GRID 12
# define DEFAULT_SPEED 3
# define DEFAULT_NICKNAME "Player"

typedef enum	e_settings
{
	SETTING_EXIT,
	SETTING_GRID_X,
	SETTING_GRID_Y,
	SETTING_SPEED,
	SETTING_NICKNAME,
	SETTING_DEFAULT,
	SETTING_USER
}				t_settings;

typedef struct	s_usersets
{
	short	USERSETS_GRIDX;
	short	USERSETS_GRIDY;
	short	USERSETS_SPEED;
	short	USERSETS_NICKNAME;
}				t_usersets;

t_settings	settingsmenu;

void	ft_settings_change(short setting);
char	*ft_settings_setnickname(char *nickname, short setmode);
void	ft_settings_default(t_game *def);
void	ft_settings_user(t_usersets *us);

#endif
